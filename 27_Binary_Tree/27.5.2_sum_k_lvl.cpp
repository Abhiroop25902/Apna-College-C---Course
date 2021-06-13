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

//k is zero indexed
int sum_k_lvl(node<int> *root, int k)
{
    if (root == nullptr)
        return -1;

    queue<node<int> *> q;
    q.push(root);
    q.push(nullptr);

    int sum = 0;
    int curr_lvl = 0;

    while (!q.empty())
    {
        if (q.front() == nullptr)
        {
            q.pop();
            curr_lvl++;

            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            node<int> *temp = q.front();
            q.pop();

            if (curr_lvl == k)
                sum += temp->data;

            if (temp->l_child != nullptr)
                q.push(temp->l_child);

            if (temp->r_child != nullptr)
                q.push(temp->r_child);
        }
    }
    return sum;
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

    int k;
    cin >> k;

    cout << sum_k_lvl(root, k);
}