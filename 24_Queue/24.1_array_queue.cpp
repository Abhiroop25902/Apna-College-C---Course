#include <iostream>
using namespace std;
#define DEFAULT_ARR_SIZE 5
#define DEFAULT_INCREASE_SIZE 2

typedef unsigned int u_int;

template <typename T>
class queue
{
    T *arr;
    int front;
    int back;
    u_int arr_size;

    void readjust();
    void increase_size();

public:
    queue() : front(-1), back(-1), arr_size(DEFAULT_ARR_SIZE)
    {
        arr = new T[DEFAULT_ARR_SIZE];
    }

    void enqueue(const T &data);
    void dequeue();
    T peek();
    bool empty() { return (front == -1); }
};

template <typename T>
void queue<T>::readjust()
{
    // cout << "readjust\n";
    u_int counter = 0;

    for (int i = front; i <= back; i++)
    {
        arr[counter] = arr[i];
        counter++;
    }

    front = 0;
    back = counter - 1;
}

template <typename T>
void queue<T>::increase_size()
{
    // cout << "increase_size\n";
    T *new_arr = new T[arr_size + DEFAULT_INCREASE_SIZE];

    for (int i = 0; i < arr_size; i++)
        new_arr[i] = arr[i];

    arr_size += DEFAULT_INCREASE_SIZE;

    delete[] arr;
    arr = new_arr;
}

template <typename T>
void queue<T>::enqueue(const T &data)
{
    if (back == -1)
        front++;

    if (back == arr_size - 1)
    {
        if (front == 0)
            increase_size();
        else
            readjust();
    }

    back++;
    arr[back] = data;
}

template <typename T>
void queue<T>::dequeue()
{
    if (front == -1)
        cout << "Queue Empty";
    else
    {
        front++;

        if (front > back)
        {
            front = -1;
            back = -1;
        }
    }
}

template <typename T>
T queue<T>::peek()
{
    if (front == -1)
        throw invalid_argument("queue_empty");

    return arr[front];
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