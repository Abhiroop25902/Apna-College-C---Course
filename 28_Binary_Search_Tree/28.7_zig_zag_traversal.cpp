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

void print_level_order(node *root)
{
    if(root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    node *temp;
    bool even_level = true; //root is level 0

    while (!q.empty())
    {
        int num_item_level = q.size();

        if (even_level)
        {
            for (int i = 0; i < num_item_level; i++)
            {
                temp = q.front();
                q.pop();
                cout << temp->val << " ";

                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
        }
        else
        {
            stack<int> stk;
            for (int i = 0; i < num_item_level; i++)
            {
                temp = q.front();
                q.pop();
                stk.push(temp->val);

                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }

            while (!stk.empty())
            {
                cout << stk.top() << " ";
                stk.pop();
            }
        }
        cout << "\n";
        even_level = !even_level;
    }
}


int main()
{
    /*
                  1
                /   \
               2      3
                \      \
                 4      5
                / \  
               6   7  
    */

    node *root = new node(1);

    root->left = new node(2);
    root->left->right = new node(4);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->right = new node(3);
    root->right->right = new node(5);

 

    print_level_order(root);
}