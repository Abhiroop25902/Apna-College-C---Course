#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//https://www.spoj.com/problems/EXPEDI/

bool comparator(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int expedi()
{
    int num_stops;
    cin >> num_stops;

    // pair : distance from town to shop, amount of fuel in that shop
    vector<pair<int, int>> stops(num_stops);
    //adding starting pos
    for (int i = 0; i < num_stops; i++)
        cin >> stops[i].first >> stops[i].second;

    //L-> distance of truck and town
    //P->initial amount of fuel
    int L, P;
    cin >> L >> P;

    //updateing stops position to be respect to car
    //<----------O(n)--------------->
    for (int i = 0; i <= num_stops; i++)
        stops[i].first = L - stops[i].first;

    //sorting according to first value in ascending
    //<----------O(nlgn)-------->
    sort(stops.begin(), stops.end(), comparator);

    int current_fuel = P;
    int stop_count = 0;

    //priority queue for max_heap of fuel containers
    priority_queue<int, vector<int>> max_heap;

    for (int i = 0; i < stops.size(); i++)
    {
        if (current_fuel >= L)
            break;

        while (current_fuel < stops[i].first)
        {
            if (max_heap.empty())
                return -1;

            stop_count++;
            current_fuel += max_heap.top();
            max_heap.pop();
        }

        max_heap.push(stops[i].second);
    }

    while (!max_heap.empty() && current_fuel < L)
    {
        current_fuel += max_heap.top();
        max_heap.pop();
        stop_count++;
    }

    if (current_fuel < L)
        return -1;
    return stop_count; //ignore last stop as it's town
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << expedi();
    }
}