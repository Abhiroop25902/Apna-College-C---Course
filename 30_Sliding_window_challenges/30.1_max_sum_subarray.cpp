/*
    For a given array and integer k and x, 
    find the maximum sum subarray of size K and having sum less than X
*/

#include <iostream>
#include <vector>
using namespace std;

int maximum_sum_subarray(vector<int> arr, int k, int x)
{
    if (k > arr.size())
        return -1;

    int left_ptr = 0;
    int right_ptr = 0;

    int curr_sum = 0;
    int max_sum = INT32_MIN;

    for (; right_ptr < k; right_ptr++)
    {
        curr_sum += arr[right_ptr];
    }

    if (curr_sum < x)
        max_sum = max(max_sum, curr_sum);

    while (right_ptr <= arr.size())
    {
        curr_sum -= arr[left_ptr];
        curr_sum += arr[right_ptr];
        left_ptr++;
        right_ptr++;

        if (curr_sum < x)
            max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
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

    int x;
    cin >> x;

    cout << maximum_sum_subarray(arr, k, x);
}