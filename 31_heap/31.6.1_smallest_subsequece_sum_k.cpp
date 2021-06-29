#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void heapsort(vector<int> &arr)
{
    priority_queue<int, vector<int>> pq;
    while (!arr.empty())
    {
        pq.push(arr.back());
        arr.pop_back();
    }

    while (!pq.empty())
    {
        arr.push_back(pq.top());
        pq.pop();
    }
}

int num_smallest_subsequence(vector<int> arr, int k)
{
    // sort(arr.begin(), arr.end(), greater<int>());

    heapsort(arr);

    int sum = 0;
    int count = 0;
    int curr_size = 0;
    int min_size = INT32_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        curr_size++;

        if (sum >= k)
        {
            if (curr_size < min_size)
            {
                count = 1;
                min_size = curr_size;
            }
            else if (curr_size == min_size)
                count++;

            curr_size--;
            sum -= arr[i];
        }
    }

    return count;
}

int len_smallest_subsequence(vector<int> arr, int k)
{
    heapsort(arr);

    int count = 0;
    int sum = 0;

    while (sum < k && count < arr.size())
        sum += arr[count++];

    if (sum < k)
        return -1;

    return count;
}

int main()
{
    int n;
    cin >> n;
    int temp;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    int k;
    cin >> k;

    cout << len_smallest_subsequence(arr, k);
}
