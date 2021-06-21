#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

void inorder_seq(TreeNode *root, vector<pair<int, TreeNode *> *> &seq)
{
    if (root != nullptr)
    {
        inorder_seq(root->left, seq);

        pair<int, TreeNode *> *p = new pair<int, TreeNode *>(root->val, root);
        seq.push_back(p);

        inorder_seq(root->right, seq);
    }
}

void print_inorder(TreeNode *root)
{
    if (root != nullptr)
    {
        print_inorder(root->left);
        cout << root->val << " ";
        print_inorder(root->right);
    }
}

void swap(TreeNode *&n1, TreeNode *&n2)
{
    int temp = n1->val;
    n1->val = n2->val;
    n2->val = temp;
}

void restore_BST(TreeNode *&root)
{
    vector<pair<int, TreeNode *> *> seq;

    inorder_seq(root, seq);

    pair<int, TreeNode *> *p1 = new pair<int, TreeNode *>(-1, nullptr);
    pair<int, TreeNode *> *p2 = new pair<int, TreeNode *>(-1, nullptr);

    int first_update = -1;

    for (int i = 1; i < seq.size(); i++)
    {
        if ((*seq[i - 1]).first > (*seq[i]).first)
        {
            if ((*p1).second == nullptr)
            {
                p1 = seq[i - 1];
                first_update = i;
            }
            else
            {
                p2 = seq[i];
                break;
            }
        }
    }

    if ((*p2).second == nullptr)
        p2 = seq[first_update];

    swap((*p1).second, (*p2).second);
}

int main()
{

    /*
                  60
                /    \
               70     55
              /         \
             50          80
    */

    TreeNode *tree1 = new TreeNode(60);
    tree1->left = new TreeNode(70);
    tree1->left->left = new TreeNode(50);
    tree1->right = new TreeNode(55);
    tree1->right->right = new TreeNode(80);

    print_inorder(tree1);
    cout << "\n";
    restore_BST(tree1);
    print_inorder(tree1);
}