#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        //main part of answer
        //keeps only the indexes whose values can be printed (also in sorted order)
        //print contents of dq of you are not sure
        while (!dq.empty() && (arr[dq.back()] < arr[i]))
            dq.pop_back();

        dq.push_back(i);
    }

    cout << arr[dq.front()] << " ";

    for (int i = k; i < n; i++)
    {
        if (dq.front() == i - k) //this means the max element has left the window
            dq.pop_front();

        while (!dq.empty() && (arr[dq.back()] < arr[i])) //main part of answer
            dq.pop_back();

        dq.push_back(i);

        cout << arr[dq.front()] << " ";
    }
}
