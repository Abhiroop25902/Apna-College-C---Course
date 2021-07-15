#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minNumberSquare(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
        return n;

    int minAns = INT32_MAX;
    for (int i = 1; i * i <= n; i++)
        minAns = min(minAns, minNumberSquare(n - i * i) + 1);

    return minAns;
}

//memoized DP
int recursiveUpdate(vector<int> &ans, int n)
{
    if (ans[n] == -1)
    {
        ans[n] = INT32_MAX;
        for (int i = 1; i * i <= n; i++)
            ans[n] = min(ans[n], recursiveUpdate(ans, n - i * i) + 1);
    }

    return ans[n];
}

int minNumberSquareMemoized(int n)
{
    vector<int> ans(n + 1, -1);
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    return recursiveUpdate(ans, n);
}

//bottom up
int minNumberSquareBottomUp(int n)
{
    vector<int> ans(n + 1, INT32_MAX);
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for (int i = 4; i < ans.size(); i++)
        for (int k = 1; k * k <= i; k++)
            ans[i] = min(ans[i], ans[i - k * k] + 1);

    return ans.back();
}

int main()
{
    int n;
    cin >> n;

    // cout <<minNumberSquare(n)<<endl;
    cout << minNumberSquareMemoized(n) << endl;
    cout << minNumberSquareBottomUp(n) << endl;
}