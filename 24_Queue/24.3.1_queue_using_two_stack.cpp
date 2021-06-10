#include <iostream>
using namespace std;

#include <stack>

template <typename T>
class queue
{
    stack<T> stk;
    void reverse();

public:
    void enqueue(const T &data) { stk.push(data); };
    void dequeue();
    const T peek();
    bool empty() { return stk.empty(); }
};

template <typename T>
void queue<T>::dequeue()
{
    stack<T> stk2;

    while (!stk.empty())
    {
        stk2.push(stk.top());
        stk.pop();
    }

    stk2.pop();

    while (!stk2.empty())
    {
        stk.push(stk2.top());
        stk2.pop();
    }
}

template <typename T>
const T queue<T>::peek()
{
    stack<T> stk2;

    while (!stk.empty())
    {
        stk2.push(stk.top());
        stk.pop();
    }

    T data_to_be_returned = stk2.top();

    while (!stk2.empty())
    {
        stk.push(stk2.top());
        stk2.pop();
    }

    return data_to_be_returned;
}

int main()
{
    queue<string> q;
    // cout<<q.peek();

    q.enqueue("1");
    q.enqueue("2");
    q.enqueue("3");
    q.enqueue("4");
    q.enqueue("5");

    cout << q.peek() << "\n";
    q.dequeue();

    q.enqueue("6");
    q.enqueue("7");

    while (!q.empty())
    {
        cout << q.peek() << "\n";
        q.dequeue();
    }

    q.enqueue("1");
}