#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int data[n];

    for (int i = 0; i < n; i++)
        cin >> data[i];

    int ans = 0;
    int iter = 0;
    while (iter < n && data[iter] == 0)
        iter++;

    deque<int> dq;
    dq.push_back(iter);

    bool has_reached_low = false;
    for (iter++; iter < n; iter++)
    {
        if (has_reached_low == false && data[dq.back()] < data[iter])
            has_reached_low = true;

        if (has_reached_low == true && data[dq.back()] > data[iter])
        {
            while (data[dq.front()] > data[dq.back()])
                dq.pop_front();

            int max_height = data[dq.front()];
            dq.pop_front();

            while (dq.front() != dq.back())
            {
                ans += (max_height - data[dq.front()]);
                dq.pop_front();
            }

            has_reached_low = false;
        }

        dq.push_back(iter);
    }

    cout << ans;
}