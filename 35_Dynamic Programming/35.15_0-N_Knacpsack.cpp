#include <iostream>
#include <vector>
using namespace std;

int knapsack(const vector<int> &weights, const vector<int> &values,
             int remainingCapacity, int currIdx = 0)
{
    if (currIdx == weights.size())
        return 0;

    if (remainingCapacity == 0)
        return 0;

    if (remainingCapacity - weights[currIdx] >= 0) //take or don't
        return max(knapsack(weights, values, remainingCapacity - weights[currIdx], currIdx) + values[currIdx],
                   knapsack(weights, values, remainingCapacity, currIdx + 1));
    else //can't take
        return knapsack(weights, values, remainingCapacity, currIdx + 1);
}

int dpFind(vector<vector<int>> &dpTable, const vector<int> &weights, const vector<int> &values,
           int currIdx, int remainingCapacity)
{
    if (dpTable[currIdx][remainingCapacity] != -1)
        return dpTable[currIdx][remainingCapacity];

    if (remainingCapacity - weights[currIdx] >= 0)
        dpTable[currIdx][remainingCapacity] =
            max(dpFind(dpTable, weights, values, currIdx, remainingCapacity - weights[currIdx]) + values[currIdx],
                dpFind(dpTable, weights, values, currIdx + 1, remainingCapacity));
    else
        dpTable[currIdx][remainingCapacity] = dpFind(dpTable, weights, values, currIdx + 1, remainingCapacity);

    return dpTable[currIdx][remainingCapacity];
}

int knapsack_DP(const vector<int> &weights, const vector<int> &values,
                int remainingCapacity, int currIdx = 0)
{
    vector<vector<int>> dpTable(weights.size() + 1, vector<int>(remainingCapacity + 1, -1));

    for (int i = 0; i <= weights.size(); i++)
        dpTable[i][0] = 0;

    for (int i = 0; i <= remainingCapacity; i++)
        dpTable[weights.size()][i] = 0;

    return dpFind(dpTable, weights, values, currIdx, remainingCapacity);
}

int knapsack_DP_smol(const vector<int> &weights, const vector<int> &values,
                     int W)
{
    vector<int> dp(W + 1, 0);

    for (int j = 0; j <= W; j++)
    {
        for (int i = 0; i < weights.size(); i++)
            if (j - weights[i] >= 0)
                dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
    }

    return dp[W];
}

int main()
{
    int n, W;
    cin >> n >> W;

    vector<int> weights(n);
    for (int i = 0; i < weights.size(); i++)
        cin >> weights[i];

    vector<int> values(n);
    for (int i = 0; i < values.size(); i++)
        cin >> values[i];

    cout << knapsack_DP_smol(weights, values, W);
}