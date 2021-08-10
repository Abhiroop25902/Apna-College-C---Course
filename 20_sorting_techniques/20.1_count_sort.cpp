#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n)
{
    int maxVal = arr[0];

    for (int i = 0; i < n; i++)
        maxVal = max(maxVal, arr[i]);

    int count[maxVal + 1] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    int output[n];

    for (int i = n - 1; i >= 0; i--)
        output[--count[arr[i]]] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countSort(arr, n);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}