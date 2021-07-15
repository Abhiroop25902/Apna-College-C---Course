#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int recursiveCount(vector<vector<int>> &lookupTable, const vector<int> &coins, int index, int value)
{
    if (value < 0)
        return 0;

    if (index == -1)
        return 0;

    if (lookupTable[index][value] == -1)
        lookupTable[index][value] = recursiveCount(lookupTable, coins, index, value - coins[index]) + recursiveCount(lookupTable, coins, index - 1, value);

    return lookupTable[index][value];
}

int numCount(const vector<int> &coins, int value)
{
    vector<vector<int>> lookupTable(coins.size(), vector<int>(value + 1, -1));

    for (int i = 0; i < lookupTable.size(); i++)
        lookupTable[i][0] = 1;

    return recursiveCount(lookupTable, coins, coins.size() - 1, value);
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