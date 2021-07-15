#include <iostream>
#include <vector>
#include <set>
using namespace std;

void recursiveCount(set<int, greater<int>> &coins, int value, int &count)
{
    if (value < 0)
        return;

    if (value == 0)
    {
        count++;
        return;
    }

    if (!coins.empty())
    {
        int coin = *(coins.begin());
        recursiveCount(coins, value - coin, count);
        coins.erase(coin);
        recursiveCount(coins, value, count);
        coins.insert(coin);
    }
}

int numWays(set<int, greater<int>> coins, int value)
{
    int count = 0;

    recursiveCount(coins, value, count);

    return count;
}

int main()
{
    int numCoins;
    cin >> numCoins;

    set<int, greater<int>> coins;
    int coin;
    for (int i = 0; i < numCoins; i++)
    {
        cin >> coin;
        coins.insert(coin);
    }

    int value;
    cin >> value;

    cout << numWays(coins, value);
}