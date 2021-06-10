#include <iostream>
#include <algorithm>
using namespace std;

//optimisation is in two_sum_problem
//we use two pointers to do two sum problem in O(n) [provided array is sorted]
//we then incorporate two_sum to do three_sum
//Total Time Complexity O(n^2)


//main stuff
// assuming ascending
bool two_sum(int *arr, int left, int right, int target)
{
    while (left != right)
    {
        if (arr[left] + arr[right] > target)
            right--;
        else if (arr[left] + arr[right] < target)
            left++;
        else //equal case
            return true;
    }
    return false;
}

bool three_sum()
{
    int n, target;

    cin >> n >> target;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    for (int i = 0; i < n-1; i++)
    {
        if (two_sum(arr, i + 1, n - 1, target - arr[i]) == true)
            return true;
    }

    return false;
}

int main()
{
    cout << three_sum();
}