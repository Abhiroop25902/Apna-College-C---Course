#include <iostream>
#include <string>
using namespace std;

#define DEFAULT_ARR_SIZE 10
#define DEFAULT_INCREMENT_SIZE 10

template <typename T>
class Stack
{
    T *arr;
    int top;
    u_int arr_size;

    void increase_size();

public:
    Stack() : top(-1), arr_size(DEFAULT_ARR_SIZE)
    {
        arr = new T[DEFAULT_ARR_SIZE]{0};
    }
    void push(const T data);
    T pop();
    T top_element();
    bool is_empty() { return (top == -1); }
};

template <typename T>
void Stack<T>::increase_size()
{
    T *new_arr = new T[arr_size + DEFAULT_INCREMENT_SIZE];

    for (int i = 0; i < arr_size; i++)
        new_arr[i] = arr[i];

    delete[] arr;

    arr_size += DEFAULT_INCREMENT_SIZE;
    arr = new_arr;
}

template <typename T>
void Stack<T>::push(const T data)
{
    if (top == arr_size - 1)
        increase_size();

    top++;
    arr[top] = data;
}

template <typename T>
T Stack<T>::pop()
{
    if (is_empty())
    {
        cout << "Stack already empty\n";
        return -1;
    }
    else
    {
        top--;
        return arr[top + 1];
    }
}

template <typename T>
T Stack<T>::top_element()
{
    if (is_empty())
        cout << "Array Empty\n";
    else
        return arr[top];

    return -1;
}

int main()
{
    int t;

    cin >> t;
    string str;

    Stack<char> s;

    while (t--)
    {
        cin >> str;

        for (char i : str)
            s.push(i);

        while (!s.is_empty())
            cout << s.pop();
        
        cout<<'\n';
    }
}
