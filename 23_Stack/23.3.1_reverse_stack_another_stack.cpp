#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void insert_bottom(stack<T> &stk, T element)
{
    if (stk.empty())
    {
        stk.push(element);
        return;
    }

    int top_element = stk.top();
    stk.pop();

    insert_bottom(stk, element);

    stk.push(top_element);
}

template <typename T>
void reverse_stack(stack<T> &stk)
{
    if (stk.empty())
    {
        return;
    }

    T top_element = stk.top();
    stk.pop();
    reverse_stack(stk);
    insert_bottom(stk, top_element);
}

int main()
{
    stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    reverse_stack(s1);

    cout << s1.top();
}