#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int optimal_merge_pattern(vector<int> comp_times)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < comp_times.size(); i++)
        min_heap.push(comp_times[i]);

    int total_cost = 0;

    while (!min_heap.empty())
    {
        if (min_heap.size() == 1)
            break;

        int min1 = min_heap.top();
        min_heap.pop();

        int min2 = min_heap.top();
        min_heap.pop();

        min_heap.push(min1 + min2);

        total_cost += min1 + min2;
    }

    return total_cost;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << optimal_merge_pattern(arr);
}
