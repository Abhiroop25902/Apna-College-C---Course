#include <iostream>
#include <limits.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(const int &key) : data(key), left(nullptr), right(nullptr) {}
};

void print_preorder(node *&root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

node *reconstruct_from_pre_order(node *&root, int *preorder_sequence, const int &seq_size, int &seq_iter, int min_value = INT_MIN, int max_val = INT_MAX)
{
    if (seq_iter >= seq_size)
        return nullptr;

    int data = preorder_sequence[seq_iter];
    if (data < min_value || data > max_val)
        return nullptr;

    node *new_node = new node(data);
    seq_iter++;
    new_node->left = reconstruct_from_pre_order(new_node->left, preorder_sequence, seq_size, seq_iter, min_value, data);
    new_node->right = reconstruct_from_pre_order(new_node->right, preorder_sequence, seq_size, seq_iter, data, max_val);

    return new_node;
}

int main()
{
    int arr[5] = {10, 2, 1, 13, 11};

    node *root = nullptr;
    int iter = 0;

    root = reconstruct_from_pre_order(root, arr, 5, iter);

    print_preorder(root);

    return 0;
}