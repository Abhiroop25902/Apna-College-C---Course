#include <iostream>
#include <vector>
using namespace std;

class Knapsack01
{
    ////pair: value, weight
    vector<pair<int, int>> items;
    int sackCapacity;

public:
    Knapsack01(vector<pair<int, int>> gItems, int gSackCapacity) : items(gItems), sackCapacity(gSackCapacity) {}
    int calculate();
};

int Knapsack01::calculate()
{
    vector<vector<int>> lookupTable(items.size() + 1, vector<int>(sackCapacity + 1, -1));

    for (int i = 0; i < lookupTable.size(); i++)
        lookupTable[i][0] = 0;

    for (int j = 0; j < lookupTable[0].size(); j++)
        lookupTable[0][j] = 0;

    for (int i = 1; i < lookupTable.size(); i++)
    {
        for (int j = 1; j < lookupTable[i].size(); j++)
        {
            if (j - items[i - 1].second < 0)
                lookupTable[i][j] = lookupTable[i - 1][j];
            else
                lookupTable[i][j] = max(lookupTable[i - 1][j], lookupTable[i - 1][j - items[i - 1].second] + items[i - 1].first);
        }
    }

    return lookupTable[items.size()][sackCapacity];
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
