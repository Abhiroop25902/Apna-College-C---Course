#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> ans;

int main()
{
    int n;
    cin >> n;

    arr = vector<int>(n);
    ans = vector<int>(n, 1);

    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];

    int maxAns = INT32_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                ans[i] = max(ans[i], 1 + ans[j]);
        }
        maxAns = max(maxAns, ans[i]);
    }

    cout << maxAns;
}