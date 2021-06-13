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

int main()
{
    /*
                  1
                /   \
               2      3  
              / \
             4   5
    */

    node<int> *root = new node<int>(1);
    root->l_child = new node<int>(2);
    root->r_child = new node<int>(3);

    root->l_child->l_child = new node<int>(4);
    root->l_child->r_child = new node<int>(5);
}