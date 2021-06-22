/*
given an array with n elements that represents position along a straight line. find k elements such that min. dist b/w any 2 points in subset in maximum possible
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool isfeasible(int mid, int *arr, int n, int k)
{
    int pos = arr[0];
    int elements = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;

            if (elements == k)
                return true;
        }
    }

    return false;
}

int largestMinDistance(int *arr, int n, int k)
{
    sort(arr, arr + n);

    int result = -1;
    int left = 1;
    int right = arr[n - 1];

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (isfeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid;
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout<<largestMinDistance(arr, n, k);
}
