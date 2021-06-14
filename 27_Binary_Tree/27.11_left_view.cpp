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

//the node* immediately after nullptr of a level will be leftmost node of next level
template <typename T>
void left_view_v1(node<T> *root)
{
    if (root == nullptr)
        return;

    queue<node<T> *> q;
    q.push(root);
    q.push(nullptr);
    node<T> *save = nullptr;
    node<T> *temp = nullptr;

    while (!q.empty())
    {
        save = temp;
        temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            if (save == nullptr)
                cout << temp->data << " ";

            if (temp->l_child != nullptr)
                q.push(temp->l_child);
            if (temp->r_child != nullptr)
                q.push(temp->r_child);
        }
    }
}

//differnet way of level order traversal, we pre_calculate number of elements in a level by using queue size, so we don't need to use nullptr's to signify lvl end
template <typename T>
void left_view_v2(node<T> *root)
{

    if (root == nullptr)
        return;

    queue<node<T> *> q;

    q.push(root);
    node<T> *temp;

    while (!q.empty())
    {
        int lvl_size = q.size();

        for (int i = 0; i < lvl_size; i++)
        {
            temp = q.front();
            q.pop();

            if (temp->l_child != nullptr)
                q.push(temp->l_child);
            if (temp->r_child != nullptr)
                q.push(temp->r_child);

            if (i == 0) //main part of left side view
                cout << temp->data << " ";
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

    left_view_v2(root);
}