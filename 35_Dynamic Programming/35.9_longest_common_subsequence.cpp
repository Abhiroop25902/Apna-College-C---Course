#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string str1, string str2)
{
    vector<vector<int>> dpTable(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    for (int i = 1; i < dpTable.size(); i++)
    {
        for (int j = 1; j < dpTable[i].size(); j++)
        {
            if (str1[i] == str2[j])
                dpTable[i][j] = dpTable[i - 1][j - 1] + 1;
            else
                dpTable[i][j] = max(dpTable[i - 1][j], dpTable[i][j - 1]);
        }
    }

    return dpTable[str1.size()][str2.size()];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << longestCommonSubsequence(str1, str2);
}