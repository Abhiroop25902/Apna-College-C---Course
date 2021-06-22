#include <iostream>
using namespace std;

/*
This is O(n), used the fact that sum of digits divisible by three 
*/

void add_digit_sum(int &sum, int num)
{
    while (num != 0)
    {
        sum += num % 10;
        num = num / 10;
    }
}

void sub_digit_sum(int &sum, int num)
{
    while (num != 0)
    {
        sum -= num % 10;
        num = num / 10;
    }
}

void num_div_3(int *arr, int n, int k)
{
    if (k > n)
        return;

    int digit_sum = 0;

    for (int i = 0; i < k; i++)
        add_digit_sum(digit_sum, arr[i]);

    if (digit_sum % 3 == 0)
    {
        for (int i = 0; i < k; i++)
            cout << arr[i];
        return;
    }

    for (int i = k; i < n; i++)
    {
        sub_digit_sum(digit_sum, arr[i - k]);
        add_digit_sum(digit_sum, arr[i]);

        if (digit_sum % 3 == 0)
        {
            for (int j = i - k + 1; j <= i; j++)
                cout << arr[j];
            return;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    num_div_3(arr, n, k);
}