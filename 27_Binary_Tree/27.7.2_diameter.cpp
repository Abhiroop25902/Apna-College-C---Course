#include <iostream>
using namespace std;

//in cpp struct are treated same as classes, but all data are public by default
template <typename T>
struct node
{
    T data;
    node *l_child;
    node *r_child;

    node(const T &val) : data(val), l_child(nullptr), r_child(nullptr) {}
};

//here return value is height and ans is diameter
template <typename T>
int height_diameter(node<T> *root, int &ans)
{
    if (root == nullptr)
        return 0;

    //this recursive call is making sure ans is max(l_diameter,r_diameter)
    int l_height = height_diameter(root->l_child, ans);
    int r_height = height_diameter(root->r_child, ans);

    ans = max(ans, 1 + l_height + r_height);

    return 1 + max(l_height, r_height);
}

int main()
{
    /*
                  5
                /   \
               6      3  
              / \    / \
             9   1  2   1
                /    \ 
               2      6
              / \      \
             3   5      7 
    */

    node<int> *root = new node<int>(5);

    root->l_child = new node<int>(6);

    root->l_child->l_child = new node<int>(9);
    root->l_child->r_child = new node<int>(1);

    root->l_child->r_child->l_child = new node<int>(2);

    root->l_child->r_child->l_child->l_child = new node<int>(3);
    root->l_child->r_child->l_child->r_child = new node<int>(5);

    root->r_child = new node<int>(3);

    root->r_child->l_child = new node<int>(2);
    root->r_child->r_child = new node<int>(1);

    root->r_child->l_child->r_child = new node<int>(6);

    root->r_child->l_child->r_child->r_child = new node<int>(7);

    int diameter = 0;

    cout << "height: " << height_diameter(root, diameter) << "\n";
    cout << "diameter: " << diameter << "\n";
}