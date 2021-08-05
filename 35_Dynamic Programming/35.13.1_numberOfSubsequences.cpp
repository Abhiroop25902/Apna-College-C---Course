// https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/

#include <iostream>
#include <vector>
using namespace std;

int numberOfSubsequence(string a, string b, int aIdx, int bIdx)
{
    if (aIdx == 0 && bIdx == 0)
        return 1;

    if (bIdx == 0)
        return 1;

    if (aIdx == 0)
        return 0;

    if (a[aIdx - 1] == b[bIdx - 1])
        return numberOfSubsequence(a, b, aIdx - 1, bIdx) + numberOfSubsequence(a, b, aIdx - 1, bIdx - 1);
    else
        return numberOfSubsequence(a, b, aIdx - 1, bIdx);
}

int numberOfSubsequence_DP(string a, string b)
{
    vector<vector<int>> dp_table(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int i = 0; i < dp_table.size(); i++)
        dp_table[i][0] = 1;

    for (int i = 1; i < dp_table.size(); i++)
        for (int j = 1; j < dp_table[i].size(); j++)
            if (a[i - 1] == b[j - 1])
                dp_table[i][j] = dp_table[i - 1][j - 1] + dp_table[i - 1][j];
            else
                dp_table[i][j] = dp_table[i - 1][j];

    return dp_table[a.length()][b.length()];
}

void recurse(string a, int &ans, int idx = 0)
{
    if (idx == a.length())
    {
        ans += numberOfSubsequence_DP(a, "abc");
        // ans += numberOfSubsequence(a, "abc", a.length(), 3);
        return;
    }

    if (a[idx] == '?')
    {
        string temp = a;
        temp[idx] = 'a';
        recurse(temp, ans, idx + 1);
        temp[idx] = 'b';
        recurse(temp, ans, idx + 1);
        temp[idx] = 'c';
        recurse(temp, ans, idx + 1);
    }
    else
        recurse(a, ans, idx + 1);
}

int numberOfSubsequences(string a)
{
    int ans = 0;

    recurse(a, ans);

    return ans;
}

int numberOfSubsequences_DP(string str)
{
    int e = 1;
    int a = 0;
    int ab = 0;
    int abc = 0;

    for (auto i : str)
    {
        if (i == 'a')
            a = a + e;

        if (i == 'b')
            ab = ab + a;

        if (i == 'c')
            abc = abc + ab;

        if (i == '?')
        {
            abc = 3 * abc + ab;
            ab = 3 * ab + a;
            a = 3 * a + e;
            e = 3 * e;
        }

        // cout << e << " " << a << " " << ab << " " << abc << endl;
    }

    return abc;
}

int main()
{
    string a;
    cin >> a;
    cout << numberOfSubsequences_DP(a);
}