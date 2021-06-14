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
void preorder(node<T> *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->l_child);
    preorder(root->r_child);
}

//steps:
// flatten left and right side
//make left end's right = root->right
//root->right = root->left;
//root->right = null
template <typename T>
void flatten(node<T> *root)
{
    if (root == nullptr)
        return;

    flatten(root->l_child); //recursively flatten left and right subtree
    flatten(root->r_child);

    //now we just need to change the links
    node<T> *temp = root->l_child;

    if (temp != nullptr)
    {
        //going to end of left_subtree
        while (temp->r_child != nullptr)
            temp = temp->r_child;

        temp->r_child = root->r_child;
        root->r_child = root->l_child;
        root->l_child = nullptr;
    }
}

//differnet way of level order traversal, we pre_calculate number of elements in a level by using queue size, so we don't need to use nullptr's to signify lvl end
template <typename T>
void level_order_tranversal(node<T> *root)
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

            cout << temp->data << " ";

            if (temp->l_child != nullptr)
                q.push(temp->l_child);
            if (temp->r_child != nullptr)
                q.push(temp->r_child);
        }

        cout << "\n";
    }
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

    preorder(root);
    cout << "\n";
    flatten(root);
    level_order_tranversal(root);
}