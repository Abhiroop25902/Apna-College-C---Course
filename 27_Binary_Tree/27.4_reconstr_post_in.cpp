#include <iostream>
using namespace std;

//in cpp struct are treated same as classes, but all data are public by default
template <typename T>
struct node
{
    T data;
    node *l_child;
    node *r_child;

    node(const T &val) : data(val), l_child(nullptr), r_child(nullptr) {}
};

//NOTE: Binary Search will not work here as it's not confirmed that array will be sorted
template <typename T>
int linear_search(T *arr, const int &n, const T &data) //start here is 0 always as recursion is changing the arr address as well
{
    for (int i = 0; i < n; i++)
        if (arr[i] == data)
            return i;

    return -1;
}

template <typename T> //just to give tree output in different way for cross checking
void pre_order_print(node<T> *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    pre_order_print(root->l_child);
    pre_order_print(root->r_child);
}

template <typename T>
node<T> *reconstruct_post_in(T *post_order, T *in_order, const int &pre_order_size, const int &in_order_size, int &iter) //call by reference of iter is important, gives static type vibes
{
    if (iter < 0 || in_order_size == 0)
        return nullptr;

    node<T> *root = new node<T>(post_order[iter]);

    int pos = linear_search(in_order, in_order_size, post_order[iter]);
    iter--; //gets reflected everywhere during recursive function call

    if (pos == -1) //just a backup if search fails, although it shouldn't
        return nullptr;

    //if pos is given index of arr, left side size of arr will be pos, and right side size will be arr_size-pos-1
    root->r_child = reconstruct_post_in(post_order, &in_order[pos + 1], pre_order_size, in_order_size - pos - 1, iter); //right side arr start position will be arr[pos+1]
    root->l_child = reconstruct_post_in(post_order, in_order, pre_order_size, pos, iter);                               //left side arr starting position is arr itself

    return root;
}

int main()
{
    int n;
    cin >> n;

    string post_order[n];
    for (int i = 0; i < n; i++)
        cin >> post_order[i];

    string in_order[n];
    for (int i = 0; i < n; i++)
        cin >> in_order[i];

    int iter = n - 1;

    node<string> *root = reconstruct_post_in(post_order, in_order, n, n, iter);

    pre_order_print(root);
}