#include <iostream>
#include <vector>
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

//bool signifies whether found ot not, path signifies actual path
template <typename T>
bool find_path(const node<T> *root, const T &key, vector<T> &path)
{
    if (root == nullptr)
        return false;

    path.push_back(root->data);
    if (root->data == key)
        return true;

    if (find_path(root->l_child, key, path) == false && find_path(root->r_child, key, path) == false)
    {
        path.pop_back();
        return false;
    }
    else
        return true;
}

template <typename T>
T lowest_common_ancestor(const node<T> *root, const T &key1, const T &key2)
{
    vector<T> path1;
    vector<T> path2;

    if (find_path(root, key1, path1) == false || find_path(root, key2, path2) == false)
        throw invalid_argument("elements not in tree");

    int i;
    for (i = 0; i < min(path1.size(), path2.size()); i++)
    {
        if (path1[i] != path2[i])
            break; //i wil never be zero as 0th element will always be root, same for every path
    }

    return path1[i - 1];
}

//uses recursion itself to find and report lowest common ancestor
template <typename T>
node<T> *lowest_common_ancestor_v2(node<T> *root, const T &key1, const T &key2)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == key1 || root->data == key2)
        return root;

    node<T> *leftLCA = lowest_common_ancestor_v2(root->l_child, key1, key2);
    node<T> *rightLCA = lowest_common_ancestor_v2(root->r_child, key1, key2);

    if (leftLCA != nullptr && rightLCA != nullptr)
        return root;

    if (leftLCA == nullptr && rightLCA == nullptr)
        return nullptr;

    if (leftLCA != nullptr)
        return leftLCA;

    return rightLCA;
}

int main()
{
    /* 
                  5
                /   \
               6      3
              / \    / \
             9   4  2   1
                /    \ 
               8      6
              / \      \
             10  11     7
    */

    node<string> *root = new node<string>("5");

    root->l_child = new node<string>("6");
    root->l_child->l_child = new node<string>("9");
    root->l_child->r_child = new node<string>("4");
    root->l_child->r_child->l_child = new node<string>("8");
    root->l_child->r_child->l_child->l_child = new node<string>("10");
    root->l_child->r_child->l_child->r_child = new node<string>("11");
    root->r_child = new node<string>("3");
    root->r_child->l_child = new node<string>("2");
    root->r_child->r_child = new node<string>("1");
    root->r_child->l_child->r_child = new node<string>("6");
    root->r_child->l_child->r_child->r_child = new node<string>("7");

    vector<string> path;
    string s1("1");
    string s2("7");

    cout << lowest_common_ancestor_v2(root, s1, s2)->data;
}