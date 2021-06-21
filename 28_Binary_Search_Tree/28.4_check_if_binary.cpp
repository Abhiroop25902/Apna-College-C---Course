#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(const int &key) : data(key), left(nullptr), right(nullptr) {}
};

//this method is wrong; gives true for following tree
/*
                  4
                /   \
               2     7  
              /     / \
             1     3   8
    */
// bool check_if_binary(node *&root)
// {
//     if (root == nullptr)
//         return true;

//     if (root->left != nullptr)
//         if (root->data < root->left->data)
//             return false;

//     if (root->right != nullptr)
//         if (root->data > root->right->data)
//             return false;

//     return check_if_binary(root->left) && check_if_binary(root->right);
// }

//using same min, max concept from before
//using long just for safety, should also work with int
bool check_if_binary(node *root, long min_val = INT64_MIN, long max_val = INT64_MAX)
{
    if (root == nullptr)
        return true;

    if (root->data <= min_val || root->data >= max_val)
        return false;

    return check_if_binary(root->left, min_val, root->data) && check_if_binary(root->right, root->data, max_val);
}

int main()
{

    // /*
    //               5
    //             /   \
    //            6      3
    //           / \    / \
    //          9   1  2   1
    //             /    \ 
    //            2      6
    //           / \      \
    //          3   5      7
    // */

    // node *root = new node(5);

    // root->left = new node(6);
    // root->left->left = new node(9);
    // root->left->right = new node(1);
    // root->left->right->left = new node(2);
    // root->left->right->left->left = new node(3);
    // root->left->right->left->right = new node(5);
    // root->right = new node(3);
    // root->right->left = new node(2);
    // root->right->right = new node(1);
    // root->right->left->right = new node(6);
    // root->right->left->right->right = new node(7);

    // /*
    //               6
    //             /   \
    //            4      8
    //             \    /
    //              5  7
    // */

    // node *root = new node(6);

    // root->left = new node(4);
    // root->left->right = new node(5);
    // root->right = new node(8);
    // root->right->left = new node(7);

    // /*
    //               3
    //             /   \
    //            2     7
    //           /     / \
    //          1     5   8
    // */

    // node *root = new node(3);

    // root->left = new node(2);
    // root->left->left = new node(1);
    // root->right = new node(7);
    // root->right->left = new node(5);
    // root->right->right = new node(8);

    // /*
    //               4
    //             /   \
    //            2     7
    //           /     / \
    //          1     3   8
    // */

    // node *root = new node(4);

    // root->left = new node(2);
    // root->left->left = new node(1);
    // root->right = new node(7);
    // root->right->left = new node(3);
    // root->right->right = new node(8);

    /*
                  2
                /   \
               2     2
    */

    node *root = new node(2);

    root->left = new node(2);
    root->right = new node(2);

    if (check_if_binary(root))
        cout << "true";
    else
        cout << "false";

    return 0;
}