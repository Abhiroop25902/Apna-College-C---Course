#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class stack
{
    queue<T> q1;

public:
    void push(const T &data);
    void pop() { q1.pop(); }
    T top() { return q1.front(); }
    bool empty() { return q1.empty(); }
};

template <typename T>
void stack<T>::push(const T &data)
{
    queue<T> q2;
    q2.push(data);

    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1, q2);
}

int main()
{
    stack<string> s;

    s.push("1");
    s.push("2");
    s.push("3");
    s.push("4");
    
    while (!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }
}
