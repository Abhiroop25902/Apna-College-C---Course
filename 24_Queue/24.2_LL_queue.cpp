#include <iostream>
using namespace std;

template <typename T>
class queue
{
    struct node
    {
        T data;
        node *next;
    };

    node *make_new_node(const T &val)
    {
        node *new_node = new node;
        new_node->data = val;
        new_node->next = NULL;
        return new_node;
    }

    node *front, *back;

public:
    queue() : front(nullptr), back(nullptr) {}

    void enqueue(const T &val);
    void dequeue();
    T peek();
    bool empty() { return (front == nullptr); }
};

template <typename T>
void queue<T>::enqueue(const T &val)
{
    node *new_node = make_new_node(val);

    if (front == nullptr)
    {
        front = new_node;
        back = new_node;
    }
    else
    {
        back->next = new_node;
        back = new_node;
    }
}

template <typename T>
void queue<T>::dequeue()
{
    if (front == nullptr)
        cout << "queue already empty";
    else
    {
        node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
            back = nullptr;
    }
}

template <typename T>
T queue<T>::peek()
{
    if (front == nullptr)
        throw invalid_argument("queue empty");

    return front->data;
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