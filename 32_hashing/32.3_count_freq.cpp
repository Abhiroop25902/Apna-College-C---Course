#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

void print_freq(const vector<int> &arr)
{
    unordered_map<int, int> ump; //number and it's frequency

    for (int i = 0; i < arr.size(); i++)
        ump[arr[i]]++;

    //ump.begin() returns `map<int,int>::iterator`
    // for (auto i = ump.begin(); i != ump.end(); i++)
    // {
    //     // cout << i->first << "->" << i->second << "\n";
    //     cout << (*i).first << "->" << (*i).second << "\n";
    // }

    for (auto i : ump)
        cout << i.first << "->" << i.second << "\n";
}

// void print_freq(const vector<int> &arr)
// {
//     map<int, int> mp; //number and it's frequency

//     for (int i = 0; i < arr.size(); i++)
//     mp[arr[i]]++;

//     for (auto i = mp.rbegin(); i != mp.rend(); i++)
//         cout << (*i).first << "->" << (*i).second << "\n";
// }

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    print_freq(arr);
}