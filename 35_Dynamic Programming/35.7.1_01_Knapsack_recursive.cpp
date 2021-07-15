#include <iostream>
#include <vector>
using namespace std;

class Knapsack01
{
    ////pair: value, weight
    vector<pair<int, int>> items;
    int sackCapacity;
    int maxValue(int indexToBeConsidered, int currSackCapacityAvailable);

public:
    Knapsack01(vector<pair<int, int>> gItems, int gSackCapacity) : items(gItems), sackCapacity(gSackCapacity) {}
    int calculate();
};

int Knapsack01::maxValue(int indexToBeConsidered, int currSackCapacityAvailable)
{
    if (currSackCapacityAvailable == 0)
        return 0;
        
    if (indexToBeConsidered <= 0)
        return 0;

    if (currSackCapacityAvailable - items[indexToBeConsidered - 1].second < 0)
        return maxValue(indexToBeConsidered - 1, currSackCapacityAvailable);

    return max(maxValue(indexToBeConsidered - 1, currSackCapacityAvailable),
               maxValue(indexToBeConsidered - 1, currSackCapacityAvailable - items[indexToBeConsidered - 1].second) + items[indexToBeConsidered - 1].first);
}

int Knapsack01::calculate()
{
    return maxValue(items.size(), sackCapacity);
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
