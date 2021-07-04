#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    void add_data(vector<int> arr, map<int, vector<int>> &mp, int arr_pos = 0, const int h_dist = 0)
    {
        if (arr_pos < arr.size())
        {
            mp[h_dist].push_back(arr[arr_pos]);
            add_data(arr, mp, 2 * arr_pos + 1, h_dist - 1); //left = 2i + 1
            add_data(arr, mp, 2 * arr_pos + 2, h_dist + 1); //right = 2i + 2
        }
    }

    vector<vector<int>> verticalTraversal(vector<int> arr)
    {
        map<int, vector<int>> mp;
        add_data(arr, mp);

        vector<vector<int>> ans;
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }

        return ans;
    }

    void print_vertical_traversal(vector<int> arr)
    {
        vector<vector<int>> vertical_order = verticalTraversal(arr);

        for (auto i : vertical_order)
            for (auto j : i)
                cout << j << " ";
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution s;
    s.print_vertical_traversal(arr);
}