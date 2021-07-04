#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int coinChange(int amount)
    {
        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int num_coins = 0;

        for (int i = 0; i < coins.size(); i++)
        {
            num_coins += amount / coins[i];
            amount = amount % coins[i];

            if (amount == 0)
                break;
        }

        if (amount == 0)
            return num_coins;
        else
            return -1;
    }
};

int main()
{

    int amount;
    cin >> amount;

    Solution s;
    cout << s.coinChange(amount);
}