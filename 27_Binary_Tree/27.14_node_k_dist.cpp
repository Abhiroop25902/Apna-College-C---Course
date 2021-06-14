#include <iostream>
#include <queue>
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
bool dist_node(node<T> *&root, node<T> *&key_node, int &dist)
{
    if (root == nullptr)
        return false;

    if (root == key_node)
    {
        key_node = root;
        return true;
    }

    dist++;

    if (dist_node(root->l_child, key_node, dist) == false && dist_node(root->r_child, key_node, dist) == false)
    {
        dist--;
        return false;
    }
    return true;
}

template <typename T>
void print_k_dist(node<T> *&target_node, const int k)
{
    if (target_node == nullptr)
        return;

    if (k == 0)
    {
        cout << target_node->data << " ";
        return;
    }

    if (target_node->l_child != nullptr) //condition not required but still
        print_k_dist(target_node->l_child, k - 1);

    if (target_node->r_child != nullptr) //condition not required but still
        print_k_dist(target_node->r_child, k - 1);
}

template <typename T>
void node_k_dist(node<T> *&root, node<T> *&key_node, int k)
{
    if (root == nullptr)
        return;

    int ld = 1;
    int rd = 1;

    print_k_dist(key_node, k);

    bool in_left = dist_node(root->l_child, key_node, ld);
    bool in_right = dist_node(root->r_child, key_node, rd);

    if (in_left)
        if (k - ld == 0)
            cout << root->data << " ";
        else
            print_k_dist(root->r_child, k - ld - 1);
    else if (in_right)
        if (k - ld == 0)
            cout << root->data << " ";
        else
            print_k_dist(root->l_child, k - rd - 1);
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

    node_k_dist(root, root->r_child, 1);
}