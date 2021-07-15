#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int numCount(const vector<int> &coins, int value)
{
    vector<int> lookupTable(value + 1, 0);

    lookupTable[0] = 1;

    for (int i = 1; i <= coins.size(); i++)
        for (int j = 0; j < lookupTable.size(); j++)
            if (j - coins[i - 1] >= 0)
                lookupTable[j] += lookupTable[j - coins[i - 1]];

    return lookupTable[value];
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