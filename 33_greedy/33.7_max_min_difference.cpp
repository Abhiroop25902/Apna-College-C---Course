#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    long long min = 0, max = 0;

    for (int i = 0; i < n / 2; i++)
    {
        max += abs(arr[i + n / 2] - arr[i]);
        min += abs(arr[2 * i + 1] - arr[2 * i]);
    }

    cout << min << " " << max;
}
