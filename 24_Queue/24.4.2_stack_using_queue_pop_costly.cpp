#include <iostream>
#include <queue>
using namespace std;

typedef unsigned int u_int;

template <typename T>
class stack
{
    u_int num_elements;
    queue<T> q1;

public:
    stack() : num_elements(0) {}
    void push(const T &data);
    void pop();
    T top() { return q1.back(); }
    bool empty() { return q1.empty(); }
};

template <typename T>
void stack<T>::push(const T &data)
{
    q1.push(data);
    num_elements++;
}

template <typename T>
void stack<T>::pop()
{
    if (empty())
        return;
        
    queue<T> q2;

    for (int i = 0; i < num_elements - 1; i++)
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();

    num_elements--;

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
