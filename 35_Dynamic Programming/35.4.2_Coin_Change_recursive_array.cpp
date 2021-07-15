#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int recursiveCount(int *coins, int index, int value)
{
    if (value < 0)
        return 0;

    if (value == 0)
        return 1;

    if (index == -1)
        return 0;

    return recursiveCount(coins, index, value - coins[index]) + recursiveCount(coins, index - 1, value);
}

int main()
{
    int numCoins;
    cin >> numCoins;

    int coins[numCoins];
    for (int i = 0; i < numCoins; i++)
        cin >> coins[i];

    int value;
    cin >> value;

    cout << recursiveCount(coins, numCoins - 1, value);
}