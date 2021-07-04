#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int num_subarray_sum_0(vector<int> arr)
{
    unordered_map<int, vector<int>> ump;

    int sum = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        ump[sum].push_back(i);
    }

    if(sum == 0)
        count++;

    for (auto i : ump)
    {
        int vec_size = i.second.size();
        count += (vec_size * (vec_size - 1)) / 2;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << num_subarray_sum_0(arr);
}