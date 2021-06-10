#include <iostream>
#include <deque>
#include <vector>
using namespace std;

//need to find longest subarray with max_num_zeroes zeroes, then output differences of indexes

int main()
{
    int n, max_num_zeroes;
    cin >> n >> max_num_zeroes;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0;
    int right = 0;
    int zero_count = 0;
    int ans = 0;

    for (; right < n; right++)
    {
        if (arr[right] == 0)
            zero_count++;

        while (zero_count > max_num_zeroes)
        {
            if (arr[left] == 0)
                zero_count--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans;
}
