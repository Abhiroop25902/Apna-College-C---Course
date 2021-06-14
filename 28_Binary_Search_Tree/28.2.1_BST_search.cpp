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

node *searchBST(node *&root, const int &key)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == key)
        return root;
    else if (root->data > key)
        return searchBST(root->left, key);
    else //root->data < key
        return searchBST(root->right, key);
}

int main()
{
    node *root = nullptr;

    int arr[6] = {5, 1, 3, 4, 2, 7};

    for (int i : arr)
        root = insertBST(root, i);

    print_inorder(root);
    cout << "\n";

    for (int i : arr)
    {
        node *temp = searchBST(root, i);

        if (temp != nullptr)
            cout << temp->data << " ";
        else
            cout << "Not Found ";
    }
    cout << "\n";

    node *temp = searchBST(root, 100);

    if (temp != nullptr)
        cout << temp->data << " ";
    else
        cout << "Not Found ";

    return 0;
}