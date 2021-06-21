#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(7);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << s.size() << endl;

    s.erase(3);

    for (auto i : s)
        cout << i << " ";
    cout << endl;
}