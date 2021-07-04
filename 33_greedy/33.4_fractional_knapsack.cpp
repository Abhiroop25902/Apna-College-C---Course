#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ratio_compare(pair<int, int> a, pair<int, int> b)
{
    return ((float)a.first) / a.second > ((float)b.first) / b.second;
}

int fractional_knapsack(vector<pair<int, int>> &data, int W)
{
    //pair content: value,weight

    sort(data.begin(), data.end(), ratio_compare);

    int idx = 0;
    int price = 0;

    while (W > 0)
    {
        if (data[idx].second <= W)
        {
            price += data[idx].first;
            W -= data[idx].second;
        }
        else
        {
            price += ((float)data[idx].first) / data[idx].second * W;
            break;
        }
        idx++;
    }

    return price;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> data(n);

    for (int i = 0; i < n; i++)
        cin >> data[i].first >> data[i].second;

    int W;
    cin >> W;

    cout << fractional_knapsack(data, W);
}
