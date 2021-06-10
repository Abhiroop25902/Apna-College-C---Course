#include <iostream>
#include <stack>
#include <utility> //for pair
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<pair<int, int>> stk;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p(arr[i], 1);

        if (stk.empty())
            stk.push(p);
        else
        {
            while (p.first > stk.top().first)
            {
                p.second += stk.top().second;
                stk.pop();
            }

            stk.push(p);
        }

        cout << p.second << " ";
    }
}