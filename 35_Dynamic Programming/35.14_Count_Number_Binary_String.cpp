#include <iostream>
#include <vector>
using namespace std;

int recurse(int stringSize, int idx, bool currBit)
{
    if (idx == stringSize - 1)
        return 1;

    if (currBit == 0)
        return recurse(stringSize, idx + 1, 0) + recurse(stringSize, idx + 1, 1);
    else //currBit == 1
        return recurse(stringSize, idx + 1, 0);
}

int numBinaryString(int stringSize)
{
    return recurse(stringSize, 0, 0) + recurse(stringSize, 0, 1);
}

int numBinaryString_DP(int stringSize)
{
    vector<vector<int>> dpTable(2, vector<int>(stringSize, 0));

    for (int i = 0; i < dpTable.size(); i++)
        dpTable[i][stringSize - 1] = 1;

    for (int i = stringSize - 2; i >= 0; i--)
    {
        dpTable[0][i] = dpTable[0][i + 1] + dpTable[1][i + 1];
        dpTable[1][i] = dpTable[0][i + 1];
    }

    return dpTable[0][0] + dpTable[1][0];
}

int main()
{
    int n;
    cin >> n;

    cout << numBinaryString_DP(n);
}