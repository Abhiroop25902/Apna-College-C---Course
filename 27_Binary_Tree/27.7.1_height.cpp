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

template <typename T>
int height(node<T> *root)
{
    if (root != nullptr)
        return max(height(root->l_child), height(root->r_child)) + 1; //+1 for itself
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

    cout << height(root);
}