#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << s.size() << endl;

    s.erase(++s.cbegin());

    for (auto i : s)
        cout << i << " ";
    cout << endl;
}