#include <iostream>
using namespace std;

#include <stack>

class queue
{
    stack<int> stk;

public:
    void enqueue(const int &data) { stk.push(data); };
    int dequeue();
    bool empty() { return stk.empty(); }
};

int queue::dequeue()
{
    if (stk.empty())
        return -1;

    int res = stk.top();
    stk.pop();

    if (stk.empty())
        return res;

    int item = dequeue();
    stk.push(res);

    return item;
}

int main()
{
    queue q;
    // cout<<q.peek();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << q.dequeue() << "\n";

    q.enqueue(6);
    q.enqueue(7);

    while (!q.empty())
        cout << q.dequeue() << "\n";

    q.enqueue(1);
}