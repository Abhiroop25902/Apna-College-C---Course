// https://leetcode.com/problems/sliding-window-maximum/submissions/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{

    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        if (q.empty())
            q.push_back(nums[i]);
        else
        {
            if (nums[i] > q.front())
            {
                while (!q.empty())
                    q.pop_back();
                q.push_back(nums[i]);
            }
            else if (nums[i] > q.back())
            {
                while (nums[i] > q.back())
                    q.pop_back();
                q.push_back(nums[i]);
            }
            else if (nums[i] <= q.back())
                q.push_back(nums[i]);
        }
    }

    ans.push_back(q.front());

    for (int i = k; i < nums.size(); i++)
    {

        if (nums[i - k] == q.front())
            q.pop_front();

        if (q.empty())
            q.push_back(nums[i]);
        else
        {
            if (nums[i] > q.front())
            {
                while (!q.empty())
                    q.pop_back();
                q.push_back(nums[i]);
            }
            else if (nums[i] > q.back())
            {
                while (nums[i] > q.back())
                    q.pop_back();
                q.push_back(nums[i]);
            }
            else if (nums[i] <= q.back())
                q.push_back(nums[i]);
        }

        ans.push_back(q.front());
    }

    return ans;
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

    int k;
    cin >> k;

    vector<int> ans = maxSlidingWindow(arr, k);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}