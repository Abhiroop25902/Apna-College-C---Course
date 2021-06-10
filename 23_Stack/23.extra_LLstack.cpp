#include <iostream>
using namespace std;

template <typename T>
class stack
{
    struct node
    {
        T data;
        node *next;
    };

    node *top;
    node *make_new_node(const T &val)
    {
        node *new_node = new node;
        new_node->data = val;
        new_node->next = nullptr;

        return new_node;
    }

public:
    stack() : top(nullptr) {}
    void push(const T &data);
    void pop();
    T top_element() { return top->data; }
    bool empty() { return (top == nullptr); }
};

template <typename T>
void stack<T>::push(const T &data)
{
    node *new_node = make_new_node(data);

    if (top == NULL)
        top = new_node;
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

template <typename T>
void stack<T>::pop()
{
    if (top == nullptr)
        cout << "Stack already empty";
    else
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
}

int main()
{
    stack<int> stk;

    stk.push(1);
    stk.push(2);

    while (!stk.empty())
    {
        cout << stk.top_element();
        stk.pop();
    }
}
