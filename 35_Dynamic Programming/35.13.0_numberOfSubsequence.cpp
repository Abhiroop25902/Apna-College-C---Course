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

int main()
{
    string a, b;
    cin >> a >> b;

    cout << numberOfSubsequence_DP(a, b);
}