#include <iostream>
#include <vector>
using namespace std;

class Knapsack01
{
    ////pair: value, weight
    vector<pair<int, int>> items;
    int sackCapacity;
    int maxValue(vector<vector<int>> lookupTable, int indexToBeConsidered, int currSackCapacityAvailable);

public:
    Knapsack01(vector<pair<int, int>> gItems, int gSackCapacity) : items(gItems), sackCapacity(gSackCapacity) {}
    int calculate();
};

int Knapsack01::maxValue(vector<vector<int>> lookupTable, int indexToBeConsidered, int currSackCapacityAvailable)
{
    if (lookupTable[indexToBeConsidered][currSackCapacityAvailable] == -1)
    {
        if (currSackCapacityAvailable - items[indexToBeConsidered - 1].second < 0)
            lookupTable[indexToBeConsidered][currSackCapacityAvailable] = maxValue(lookupTable, indexToBeConsidered - 1, currSackCapacityAvailable);
        else
            lookupTable[indexToBeConsidered][currSackCapacityAvailable] = max(maxValue(lookupTable, indexToBeConsidered - 1, currSackCapacityAvailable),
                                                                              maxValue(lookupTable, indexToBeConsidered - 1,
                                                                                       currSackCapacityAvailable - items[indexToBeConsidered - 1].second) +
                                                                                  items[indexToBeConsidered - 1].first);
    }

    return lookupTable[indexToBeConsidered][currSackCapacityAvailable];
}

int Knapsack01::calculate()
{
    vector<vector<int>> lookupTable(items.size() + 1, vector<int>(sackCapacity + 1, -1));

    for (int i = 0; i < lookupTable[0].size(); i++)
        lookupTable[0][i] = 0;

    for (int i = 0; i < lookupTable.size(); i++)
        lookupTable[i][0] = 0;

    return maxValue(lookupTable, items.size(), sackCapacity);
}

int main()
{
    int numItems;
    cin >> numItems;

    //pair: value, weight
    vector<pair<int, int>> items(numItems);

    for (int i = 0; i < items.size(); i++)
        cin >> items[i].first >> items[i].second;

    int sackCapacity;
    cin >> sackCapacity;

    Knapsack01 k(items, sackCapacity);
    cout << k.calculate();
}
