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

//idea is very crafty, use queue to store node, and using nullptr as divider between levels
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
                  1
                /   \
               2      3  
              / \    / \
             4   5  6   7
    */

    node<string> *root = new node<string>("1");
    root->l_child = new node<string>("2");
    root->r_child = new node<string>("3");

    root->l_child->l_child = new node<string>("4");
    root->l_child->r_child = new node<string>("5");

    root->r_child->l_child = new node<string>("6");
    root->r_child->r_child = new node<string>("7");

    level_order_traversal(root);
}