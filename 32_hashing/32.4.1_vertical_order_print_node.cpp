#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
    TreeNode(int data, TreeNode* left_ptr, TreeNode* right_ptr) : val(data), left(left_ptr), right(right_ptr) {}
};

class Solution
{
public:
    void add_data(TreeNode *root, map<int, vector<int>> &mp, const int h_dist = 0)
    {
        if (root != nullptr)
        {
            mp[h_dist].push_back(root->val);
            add_data(root->left, mp, h_dist - 1);
            add_data(root->right, mp, h_dist + 1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<int>> mp;
        add_data(root, mp);

        vector<vector<int>> ans;
        for (auto i : mp)
            ans.push_back(i.second);

        return ans;
    }

    void print_vertical_traversal(TreeNode *root)
    {
        vector<vector<int>> vertical_order = verticalTraversal(root);

        for (auto i : vertical_order)
            for (auto j : i)
                cout << j << " ";
    }
};

int main()
{
    TreeNode* root = new TreeNode(10,new TreeNode(7, new TreeNode(3), new TreeNode(11)), new TreeNode(4, new TreeNode(14), new TreeNode(6)));


    Solution s;
    s.print_vertical_traversal(root);
}