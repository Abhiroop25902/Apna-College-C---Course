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

//count should be given zero
template <typename T>
void count_nodes_var_1(node<T> *root, int &count) //count call by reference to reflect actual changes
{
    if (root != nullptr)
    {
        count++;
        count_nodes(root->l_child, count);
        count_nodes(root->r_child, count);
    }
}

template <typename T>
int count_nodes_var_2(node<T> *root)
{
    if (root != nullptr)
    {
        return count_nodes_var_2(root->l_child) + count_nodes_var_2(root->r_child) + 1;
    }
    else
        return 0;
}

int main()
{
    /*
                  5
                /   \
               6      3  
              / \    / \
             9   1  2   1
                /    \ 
               2      6
              / \      \
             3   5      7 
    */

    node<int> *root = new node<int>(5);

    root->l_child = new node<int>(6);

    root->l_child->l_child = new node<int>(9);
    root->l_child->r_child = new node<int>(1);

    root->l_child->r_child->l_child = new node<int>(2);

    root->l_child->r_child->l_child->l_child = new node<int>(3);
    root->l_child->r_child->l_child->r_child = new node<int>(5);

    root->r_child = new node<int>(3);

    root->r_child->l_child = new node<int>(2);
    root->r_child->r_child = new node<int>(1);

    root->r_child->l_child->r_child = new node<int>(6);

    root->r_child->l_child->r_child->r_child = new node<int>(7);

    int count = 0;

    cout << count_nodes_var_2(root);
}