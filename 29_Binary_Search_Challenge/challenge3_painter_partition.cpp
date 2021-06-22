#include <iostream>
using namespace std;

bool is_feasible(int *arr, int n, int m, int min)
{
    int iter = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
            return false;
        else if (sum + arr[i] > min)
        {
            iter++;
            sum = arr[i];

            if (iter > m)
                return false;
        }
        else
            sum += arr[i];
    }

    if (iter < m)
        return false;
    else
        return true;
}

int painter_partition(int *arr, int n, int m)
{
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++)
        right += arr[i];

    int ans = INT32_MAX;
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (is_feasible(arr, n, m, mid))
        {
            ans = min(mid, ans);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m;
    cin>>m;

    cout<<painter_partition(arr,n,m);
}