#include <iostream>
using namespace std;

bool three_sum()
{
    int n, target;

    cin >> n >> target;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] == target)
                    return true;
        }
    }

    return false;
}

int main()
{
    cout << three_sum();
}