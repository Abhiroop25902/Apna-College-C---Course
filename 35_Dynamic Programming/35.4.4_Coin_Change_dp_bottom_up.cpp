#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int numCount(const vector<int> &coins, int value)
{
    vector<vector<int>> lookupTable(coins.size() + 1, vector<int>(value + 1, 0));

    lookupTable[0][0] = 1;

    for (int i = 1; i < lookupTable.size(); i++)
    {
        for (int j = 0; j < lookupTable[i].size(); j++)
        {
            lookupTable[i][j] += lookupTable[i - 1][j];

            if (j - coins[i - 1] >= 0)
                lookupTable[i][j] += lookupTable[i][j - coins[i - 1]];
        }
    }

    return lookupTable[coins.size()][value];
}

int main()
{
    int numCoins;
    cin >> numCoins;

    vector<int> coins(numCoins);
    for (int i = 0; i < numCoins; i++)
        cin >> coins[i];

    int value;
    cin >> value;

    cout << numCount(coins, value);
}