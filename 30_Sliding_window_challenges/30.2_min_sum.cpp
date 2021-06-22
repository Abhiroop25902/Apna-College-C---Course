#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// https://leetcode.com/problems/minimum-size-subarray-sum/
/*
    For a given array and an integer X, find the minimum subarray size for which sum >= target
*/

int minSubArrayLen(int target, vector<int> &nums)
{
    queue<int> q;
    int sum_q = 0;
    int min_len = INT32_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        q.push(nums[i]);
        sum_q += nums[i];

        while (sum_q >= target && !q.empty())
        {
            min_len = min(min_len, (int)q.size());
            sum_q -= q.front();
            q.pop();
        }
    }

    if (min_len == INT32_MAX)
        return 0;
    return min_len;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int target;
    cin >> target;

    cout << minSubArrayLen(target, arr);
}