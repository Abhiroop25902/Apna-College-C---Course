#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int *arr, int n, int m, int min)
{
    int studentsRequired = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
            return false;

        if (sum + arr[i] > min)
        {
            studentsRequired++;
            sum = arr[i];

            if (studentsRequired > m)
                return false;
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int allocateMinimumPages(int *arr, int n, int m)
{
    if (n < m)
        return -1;

    sort(arr, arr + n);

    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    int start = 0;
    int end = sum;
    int ans = INT32_MAX;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << allocateMinimumPages(arr, n, m);
}
