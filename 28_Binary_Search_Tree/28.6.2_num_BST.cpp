#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;

    node(int data) : val(data), left(nullptr), right(nullptr) {}
};

//this is recursive and is exponential; there is no way to use dp and reduce it, as all trees are different(shape might be same , but values isn't) and hence there is not overlapping
vector<node *> construct_trees(int start, int end)
{
    vector<node *> trees;

    if (start > end)
    {
        trees.push_back(nullptr);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<node *> leftSubtrees = construct_trees(start, i - 1);
        vector<node *> rightSubtrees = construct_trees(i + 1, end);

        for (int j = 0; j < leftSubtrees.size(); j++)
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                node *root = new node(i);
                root->left = leftSubtrees[j];
                root->right = rightSubtrees[k];
                trees.push_back(root);
            }
    }

    return trees;
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
    vector<node *> possible_trees = construct_trees(1, 3);

    for (int i = 0; i < possible_trees.size(); i++)
    {
        cout << i << " : ";
        print_preorder(possible_trees[i]);
        cout << "\n";
    }
}