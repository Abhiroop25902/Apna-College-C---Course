#include <iostream>
#include <stack>
using namespace std;

template <typename T>
stack<T> reverse_stack(stack<T> stk)
{
    stack<T> stk2;

    while (!stk.empty())
    {
        stk2.push(stk.top());
        stk.pop();
    }

    return stk2;
}

int main()
{
    stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    stack<int> s2 = reverse_stack(s1);

    cout << s2.top();
}