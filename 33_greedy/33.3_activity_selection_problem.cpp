#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool pair_sec_comparator(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int activity_selector(vector<pair<int, int>> &tasks)
{
    sort(tasks.begin(), tasks.end(), pair_sec_comparator);

    // for (int i = 0; i < tasks.size(); i++)
    //     cout << tasks[i].first << " " << tasks[i].second << endl;

    int activity_count = 1;
    int time_already_gone = tasks[0].second;

    for (int i = 1; i < tasks.size(); i++)
    {
        if (tasks[i].first >= time_already_gone)
        {
            time_already_gone = tasks[i].second;
            activity_count++;
        }
    }

    return activity_count;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    cout<<activity_selector(tasks);
}