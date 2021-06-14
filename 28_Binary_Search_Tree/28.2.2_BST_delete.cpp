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

void print_inorder(node *&root)
{
    if (root != nullptr)
    {
        print_inorder(root->left);
        cout << root->data << " ";
        print_inorder(root->right);
    }
}

node *deleteBST(node *root, const int &key)
{
    if (root == nullptr)
        return nullptr;

    if (root->data > key)
        root->left = deleteBST(root->left, key);
    else if (root->data < key)
        root->right = deleteBST(root->right, key);
    else //root->data == key; i.e root has to be deleted
    {
        //first two cases handle leaf and one child case
        if (root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else //case 3; both child present;
        {
            node *in_order_succ = root->right;

            while (in_order_succ->left != nullptr)
                in_order_succ = in_order_succ->left;

            root->data = in_order_succ->data;
            root->right = deleteBST(root->right, in_order_succ->data);
            return root;
        }
    }

    return root;
}

int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7};

    node *root = nullptr;

    for (int i : arr)
        root = insertBST(root, i);

    print_inorder(root);
    cout << endl;

    node *temp = nullptr;
    root = deleteBST(root, root->data);

    print_inorder(root);
    cout << "\n\n";

    return 0;
}