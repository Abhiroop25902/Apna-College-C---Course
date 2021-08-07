#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int initial, int mid, int final)
{
    int size1 = mid - initial + 1;
    int arr1[size1];
    for (int i = 0; i < size1; i++)
        arr1[i] = arr[initial + i];

    int size2 = final - mid;
    int arr2[size2];
    for (int i = 0; i < size2; i++)
        arr2[i] = arr[mid + 1 + i];

    int arr1_pos = 0;
    int arr2_pos = 0;
    int arr_pos = initial;

    while (arr1_pos < size1 && arr2_pos < size2)
    {
        if (arr1[arr1_pos] < arr2[arr2_pos])
        {
            arr[arr_pos] = arr1[arr1_pos];
            arr1_pos++;
            arr_pos++;
        }
        else
        {
            arr[arr_pos] = arr2[arr2_pos];
            arr2_pos++;
            arr_pos++;
        }
    }

    while (arr1_pos < size1)
    {
        arr[arr_pos] = arr1[arr1_pos];
        arr1_pos++;
        arr_pos++;
    }

    while (arr2_pos < size2)
    {
        arr[arr_pos] = arr2[arr2_pos];
        arr2_pos++;
        arr_pos++;
    }
}

//sorts array of int type in ascending order, put initial as 0, and final as size -1
void mergeSort(int *arr, int initial, int final)
{
    if (initial < final)
    {
        int mid = (initial + final) / 2;
        mergeSort(arr, initial, mid);
        mergeSort(arr, mid + 1, final);
        merge(arr, initial, mid, final);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}