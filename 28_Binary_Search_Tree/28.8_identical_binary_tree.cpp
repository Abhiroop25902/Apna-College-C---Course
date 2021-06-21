#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;

    node(int data) : val(data), left(nullptr), right(nullptr) {}
};

bool is_tree_identical(node *tree1, node *tree2)
{
    if (tree1 == nullptr && tree2 == nullptr)
        return true;

    if (tree1 == nullptr)
        return false;

    if (tree2 == nullptr)
        return false;

    if (tree1->val != tree2->val)
        return false;

    return is_tree_identical(tree1->left, tree2->left) && is_tree_identical(tree1->right, tree2->right);
}

int main()
{
    // /*
    //               1
    //             /   \
    //            2      3
    //             \      \
    //              4      5
    //             / \  
    //            6   7
    // */

    // node *tree1 = new node(1);
    // tree1->left = new node(2);
    // tree1->left->right = new node(4);
    // tree1->left->right->left = new node(6);
    // tree1->left->right->right = new node(7);
    // tree1->right = new node(3);
    // tree1->right->right = new node(5);

    // node *tree2 = new node(1);
    // tree2->left = new node(2);
    // tree2->left->right = new node(4);
    // tree2->left->right->left = new node(6);
    // tree2->left->right->right = new node(7);
    // tree2->right = new node(3);
    // tree2->right->right = new node(5);

    /*
                  1
                    \
                      3
                     / \
                    2   5 
    */

    node *tree1 = new node(1);
    tree1->right = new node(3);
    tree1->right->left = new node(2);
    tree1->right->right = new node(5);

    node *tree2 = new node(1);
    tree2->right = new node(3);
    tree2->right->left = new node(2);
    tree2->right->right = new node(8) ;

    if (is_tree_identical(tree1, tree2))
        cout << "true";
    else
        cout << "false";
}