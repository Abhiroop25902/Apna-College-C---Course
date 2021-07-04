#include <iostream>
#include <vector>
using namespace std;

//default sliding window
int min_sum_window_k(vector<int> arr, int k)
{
    if (arr.size() < k)
        return -1;

    int curr_win_sum = 0;
    int min_sum = INT32_MAX;

    for (int i = 0; i < k; i++)
        curr_win_sum += arr[i];

    min_sum = min(min_sum, curr_win_sum);

    for (int i = k; i < arr.size(); i++)
    {
        curr_win_sum -= arr[i - k];
        curr_win_sum += arr[i];

        min_sum = min(min_sum, curr_win_sum);
    }

    return min_sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    cout << min_sum_window_k(arr, k);
}