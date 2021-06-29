#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    struct comparator
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.first > b.first;
        }
    };

    vector<int> mergeKLists(vector<vector<int>> &arrays)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> min_heap;

        vector<int> ans;
        int idx[arrays.size()] = {0};

        for (int i = 0; i < arrays.size(); i++)
            if (idx[i] < arrays[i].size())
            {
                min_heap.push(make_pair(arrays[i][idx[i]], i));
                idx[i]++;
            }

        while (!min_heap.empty())
        {
            ans.push_back(min_heap.top().first);

            if (idx[min_heap.top().second] < arrays[min_heap.top().second].size())
                min_heap.push(make_pair(arrays[min_heap.top().second][idx[min_heap.top().second]], min_heap.top().second));

            idx[min_heap.top().second]++;

            min_heap.pop();
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> arrays;

    // vector<int> arr1 = {1, 4, 5};
    // arrays.push_back(arr1);

    // vector<int> arr2 = {1, 3, 4};
    // arrays.push_back(arr2);

    // vector<int> arr3 = {2, 6, 7};
    // arrays.push_back(arr3);

    // vector<int> arr4;
    // arrays.push_back(arr4);

    vector<int> arr1 = {1, 4, 7};
    arrays.push_back(arr1);

    vector<int> arr2 = {3, 5};
    arrays.push_back(arr2);

    vector<int> arr3 = {2, 6, 7};
    arrays.push_back(arr3);

    vector<int> arr4;
    arrays.push_back(arr4);

    Solution s;
    vector<int> ans = s.mergeKLists(arrays);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
