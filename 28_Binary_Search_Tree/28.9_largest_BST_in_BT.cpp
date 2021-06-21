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

//give tree_size 0
node *largest_BST_in_BT(node *root, int &tree_size, bool &is_prev_node_part_of_BST, const int &min_val = INT32_MIN, const int &max_val = INT32_MAX)
{
    if (root == nullptr)
        return nullptr;

    if (root->val >= max_val || root->val <= min_val)
        is_prev_node_part_of_BST = false;

    int left_tree_size = 0;
    int right_tree_size = 0;
    bool left_bool = true;
    bool right_bool = true;

    node *left_possible_BST = nullptr;
    node *right_possible_BST = nullptr;

    if (is_prev_node_part_of_BST == true)
    {
        left_possible_BST = largest_BST_in_BT(root->left, left_tree_size, left_bool, min_val, root->val);
        right_possible_BST = largest_BST_in_BT(root->right, right_tree_size, right_bool, root->val, max_val);
    }
    else
    {
        left_possible_BST = largest_BST_in_BT(root->left, left_tree_size, left_bool, INT32_MIN, root->val);
        right_possible_BST = largest_BST_in_BT(root->right, right_tree_size, right_bool, root->val, INT32_MAX);
    }

    if (left_tree_size > right_tree_size)
    {
        if (left_bool == false)
        {
            tree_size = left_tree_size;
            return left_possible_BST;
        }
        else
        {
            if (right_bool == true)
                tree_size = left_tree_size + right_tree_size + 1;
            else
                tree_size = left_tree_size + 1;
            return root;
        }
    }
    else //<=
    {
        if (right_bool == false)
        {
            tree_size = right_tree_size;
            return right_possible_BST;
        }
        else
        {
            if (left_bool == true)
                tree_size = right_tree_size + left_tree_size + 1;
            else
                tree_size = right_tree_size + 1;
            return root;
        }
    }
}

void print_preorder(node *root)
{
    if (root != nullptr)
    {
        cout << root->val << " ";
        print_preorder(root->left);
        print_preorder(root->right);
    }
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
    //            2   7
    // */

    // node *tree1 = new node(1);
    // tree1->left = new node(2);
    // tree1->left->right = new node(4);
    // tree1->left->right->left = new node(2);
    // tree1->left->right->right = new node(7);
    // tree1->right = new node(3);
    // tree1->right->right = new node(5);

    /*
                  1
                    \
                      3
                     / \
                    2   5 
    */

    // node *tree1 = new node(1);
    // tree1->right = new node(3);
    // tree1->right->left = new node(2);
    // tree1->right->right = new node(5);

    // /*
    //               5
    //             /   \
    //            3     6
    //           / \      
    //          2   4
    // */

    // node *tree1 = new node(5);
    // tree1->left = new node(3);
    // tree1->left->left = new node(2);
    // tree1->left->right = new node(4);
    // tree1->right = new node(6);

    /*
                  60
                /    \
               65     70
              /         \
             50          80
    */

    node *tree1 = new node(60);
    tree1->left = new node(65);
    tree1->left->left = new node(50);
    tree1->right = new node(70);
    tree1->right->right = new node(80);

    int tree_size = 0;
    bool a;
    print_preorder(largest_BST_in_BT(tree1, tree_size, a));
    cout << "\n"
         << tree_size;
}