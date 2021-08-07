#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int *arr, int initial, int final)
{
    int pivot_value = arr[initial];

    int left_iterator = initial;
    int right_iterator = final;

    while (true)
    {
        while (arr[left_iterator] < pivot_value)
            left_iterator++;

        while (pivot_value < arr[right_iterator])
            right_iterator--;

        if (arr[left_iterator] == arr[right_iterator])
        {
            if (left_iterator == right_iterator)
                return left_iterator;
            else
                right_iterator--;
        }
        else if (left_iterator < right_iterator)
            swap(&arr[left_iterator], &arr[right_iterator]);
        else
            return left_iterator;
    }
}

//sorts array using quick_sort algorithm, give initial as 0, and final as sizeofarray -1
void quick_sort(int *arr, int initial, int final)
{
    if (initial < final)
    {
        int pos_of_pivot = partition(arr, initial, final);
        quick_sort(arr, initial, pos_of_pivot);
        quick_sort(arr, pos_of_pivot + 1, final);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}