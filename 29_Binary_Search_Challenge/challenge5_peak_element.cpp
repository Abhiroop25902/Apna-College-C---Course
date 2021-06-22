#include <iostream>
using namespace std;

int peak_element(int *arr, int n)
{
    int left = 0;
    int right = n - 1;

    while (left >= right)
    {
        if (left == right)
            return arr[left];

        int mid = (left + right) / 2;

        if (arr[mid] < arr[mid + 1])
            left = mid;
        else if (arr[mid] > arr[mid - 1])
            right = mid;
    }
}