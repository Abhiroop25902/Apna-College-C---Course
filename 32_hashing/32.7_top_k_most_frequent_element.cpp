#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

//https://leetcode.com/problems/top-k-frequent-elements/submissions/

class Solution
{
public:
    class comparator
    {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if (a.second > b.second)
                return true;
            else
                return false;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq; //number and it's count

        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

        for (auto i : freq)
        {
            pq.push(i);

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    Solution s;

    vector<int> top_k = s.topKFrequent(arr, k);

    for (int i = 0; i < top_k.size(); i++)
        cout << top_k[i] << " ";
}