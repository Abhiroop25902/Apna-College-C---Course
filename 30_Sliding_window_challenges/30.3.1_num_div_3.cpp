#include <iostream>
using namespace std;

/*
This is O(n^2) as all gor all the subset we are recalculating answer
*/
bool is_divisible(int *arr, int i, int k, int &ret_val)
{

    string concat;

    for (int j = 0; j < k; j++)
        concat += to_string(arr[i + j]);

    int concat_num = stoi(concat);

    if (concat_num % 3 == 0)
    {
        ret_val = concat_num;
        return true;
    }
    else
        return false;
}

int num_div_3(int *arr, int n, int k)
{
    if (k > n)
        return -1;

    for (int i = 0; i < n - k + 1; i++)
    {
        int ret_val = -1;
        if (is_divisible(arr, i, k, ret_val))
            return ret_val;
    }

    return -1;
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

    cout << num_div_3(arr, n, k);
}