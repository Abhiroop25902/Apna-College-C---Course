#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // priority_queue<int, vector<int>, greater<int>> pq;

    // int arr[6] = {6, 5, 4, 3, 2, 1};

    // for (int i = 0; i < 6; i++)
    //     pq.push(arr[i]);

    // while (!pq.empty())
    // {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    priority_queue<int, vector<int>> pq;

    int arr[6] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 6; i++)
        pq.push(arr[i]);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}