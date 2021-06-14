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
node<T> *lowest_common_ancestor(node<T> *&root, const T &n1, const T &n2)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    node<T> *leftLCA = lowest_common_ancestor(root->l_child, n1, n2);
    node<T> *rightLCA = lowest_common_ancestor(root->r_child, n1, n2);

    if (leftLCA != nullptr && rightLCA != nullptr)
        return root;

    if (leftLCA == nullptr && rightLCA == nullptr)
        return nullptr;

    if (leftLCA != nullptr)
        return leftLCA;

    return rightLCA;
}

template <typename T>
bool node_dist(node<T> *&root, const T &n, int &curr_dist)
{
    if (root == nullptr)
        return false;

    if (root->data == n)
        return true;

    curr_dist++;

    if (node_dist(root->l_child, n, curr_dist) == false && node_dist(root->r_child, n, curr_dist) == false)
    {
        curr_dist--;
        return false;
    }

    return true;
}

template <typename T>
int shortest_distance(node<T> *root, const T &n1, const T &n2)
{
    node<T> *lca = lowest_common_ancestor(root, n1, n2);

    if (lca == nullptr)
        return -1;

    int d1 = 0;
    int d2 = 0;

    node_dist(lca, n1, d1);
    node_dist(lca, n2, d2);

    return d1 + d2;
}

int main()
{
    /* 
                  5
                /   \
               6      3
              / \    / \
             9   4  2   1
                /    \ 
               8      6
              / \      \
             10  11     7
    */

    node<int> *root = new node<int>(5);

    root->l_child = new node<int>(6);
    root->l_child->l_child = new node<int>(9);
    root->l_child->r_child = new node<int>(4);
    root->l_child->r_child->l_child = new node<int>(8);
    root->l_child->r_child->l_child->l_child = new node<int>(10);
    root->l_child->r_child->l_child->r_child = new node<int>(11);
    root->r_child = new node<int>(3);
    root->r_child->l_child = new node<int>(2);
    root->r_child->r_child = new node<int>(1);
    root->r_child->l_child->r_child = new node<int>(6);
    root->r_child->l_child->r_child->r_child = new node<int>(7);

    cout << shortest_distance(root, 9, 1);
}