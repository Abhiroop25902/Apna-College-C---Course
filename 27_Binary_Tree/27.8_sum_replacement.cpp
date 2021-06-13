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

//returns new value of root
template <typename T>
int sum_replacement(node<T> *root)
{
    if (root == nullptr)
        return 0;

    root->data += sum_replacement(root->l_child) + sum_replacement(root->r_child);
    return root->data;
}

//just for checking if change happened or not
template <typename T>
void level_order_traversal(node<T> *root)
{
    if (root == nullptr) //forgot this edge case
        return;

    queue<node<T> *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        if (q.front() == nullptr)
        {
            cout << "\n";
            q.pop();

            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            node<T> *temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->l_child != nullptr)
                q.push(temp->l_child);

            if (temp->r_child != nullptr)
                q.push(temp->r_child);
        }
    }
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

    //should turn to

    /*
                  50
                 /   \
               26     19  
              / \    /  \
             9   11 15   1
                /    \ 
               10     13 
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

    sum_replacement(root);

    level_order_traversal(root);
}