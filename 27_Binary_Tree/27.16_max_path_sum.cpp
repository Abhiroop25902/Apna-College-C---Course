#include <iostream>
#include <queue>
#include <limits.h>
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

int max_sum_util(node<int> *root, int &ans)
{
    if (root == nullptr)
        return 0;

    int left_sum = max_sum_util(root->l_child, ans);
    int right_sum = max_sum_util(root->r_child, ans);

    int node_sum = max(max(root->data, root->data + left_sum + right_sum),
                       max(root->data + right_sum, root->data + left_sum));
    ans = max(ans, node_sum);

    return max(root->data, max(root->data + left_sum, root->data + right_sum));
}

int max_path_sum(node<int> *&root)
{
    int ans = INT_MIN;

    max_sum_util(root, ans);

    return ans;
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

    cout << max_path_sum(root);
}