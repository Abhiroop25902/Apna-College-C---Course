#include <iostream>
#include <queue>
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

//returns height of node if balanced, else return garbage
//default result give is true
template <typename T>
int is_balanced(node<T> *root, bool &result)
{
    if (result == false || root == nullptr)
        return 0;

    int l_height = is_balanced(root->l_child, result);
    int r_height = is_balanced(root->r_child, result);

    if (abs(l_height - r_height) > 1)
        result = false;

    return max(l_height, r_height) + 1;
}

int main()
{

    //<-------------------tree 1------------------->
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

    // node<int> *root = new node<int>(5);

    // root->l_child = new node<int>(6);
    // root->l_child->l_child = new node<int>(9);
    // root->l_child->r_child = new node<int>(1);
    // root->l_child->r_child->l_child = new node<int>(2);
    // root->l_child->r_child->l_child->l_child = new node<int>(3);
    // root->l_child->r_child->l_child->r_child = new node<int>(5);
    // root->r_child = new node<int>(3);
    // root->r_child->l_child = new node<int>(2);
    // root->r_child->r_child = new node<int>(1);
    // root->r_child->l_child->r_child = new node<int>(6);
    // root->r_child->l_child->r_child->r_child = new node<int>(7);

    // //<-------------------tree 2------------------->
    // /*
    //               5
    //             /   \
    //            6      3
    //           /
    //          9
    // */

    // node<int> *root = new node<int>(5);

    // root->l_child = new node<int>(6);
    // root->l_child->l_child = new node<int>(9);
    // root->r_child = new node<int>(3);

    // //<-------------------tree 3------------------->

    // /*
    //               5
    //             /   \
    //            6      3
    //           /
    //          9
    //           \
    //            10
    // */

    // node<int> *root = new node<int>(5);

    // root->l_child = new node<int>(6);
    // root->l_child->l_child = new node<int>(9);
    // root->l_child->l_child->r_child = new node<int>(10);
    // root->r_child = new node<int>(3);

    // //<-------------------tree 4------------------->
    // /*
    //               1
    //             /   \
    //            2      3
    //           / \    / \ 
    //          4   5  6   7

    // */

    // node<int> *root = new node<int>(1);

    // root->l_child = new node<int>(2);
    // root->l_child->l_child = new node<int>(4);
    // root->l_child->r_child = new node<int>(5);
    // root->r_child = new node<int>(3);
    // root->r_child->l_child = new node<int>(6);
    // root->r_child->r_child = new node<int>(7);

    //<-------------------tree 5------------------->
    /*
                  1
                / 
               2    
              / 
             3   
  
    */

    node<int> *root = new node<int>(1);

    root->l_child = new node<int>(2);
    root->l_child->l_child = new node<int>(3);

    bool balanced = true;

    is_balanced(root, balanced);
    cout << balanced;
}