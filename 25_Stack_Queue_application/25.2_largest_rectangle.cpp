#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> s;
    int max_area = -1;
    int area;
    int width;

    for (int i = 0; i < n; i++)
    {
        if (!s.empty() && arr[i] < s.top())
        {
            width = 1;

            while (!s.empty())
            {
                area = s.top() * width;
                max_area = max(area, max_area);

                width++;
                s.pop();
            }
        }
        else
            s.push(arr[i]);
    }

    cout << max_area;

    return 0;
}