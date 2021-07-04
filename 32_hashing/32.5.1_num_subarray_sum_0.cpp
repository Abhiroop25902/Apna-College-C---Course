#include <iostream>
#include <vector>
using namespace std;

int num_subarray_sum_0(vector<int> arr)
{
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;

        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];

            if (sum == 0)
                count++;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << num_subarray_sum_0(arr);
}