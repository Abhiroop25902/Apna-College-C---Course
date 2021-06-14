#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(const int &key) : data(key), left(nullptr), right(nullptr) {}
};

node *insertBST(node *root, const int &key)
{
    if (root == nullptr)
        return new node(key);

    if (key < root->data)
        root->left = insertBST(root->left, key);
    else if (key > root->data)
        root->right = insertBST(root->right, key);

    return root;
}

void print_inorder(node *root)
{
    if (root != nullptr)
    {
        print_inorder(root->left);
        cout << root->data << " ";
        print_inorder(root->right);
    }
}

int main()
{
    node *root = nullptr;

    root = insertBST(root, 5);
    root = insertBST(root, 1);
    root = insertBST(root, 3);
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 7);

    print_inorder(root);

    return 0;
}