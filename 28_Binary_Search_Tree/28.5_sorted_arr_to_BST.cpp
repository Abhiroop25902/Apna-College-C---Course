#include <iostream>
#include <random>
#include <ctime>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(const int &key) : data(key), left(nullptr), right(nullptr) {}
};

//left_side default value = 0; right_size default_value, arr_size -1
//made very similar to our binary search, we know inorder of BST is sorted, so left side of any node, will be left in arr as well, and to minimise height, we take middle element of sub array given
node *sorted_to_BST(const int *arr, const int &arr_size, int left_side, int right_side)
{
    if (left_side < 0)
        return nullptr;

    if (right_side >= arr_size)
        return nullptr;

    if (left_side > right_side)
        return nullptr;

    int mid = (left_side + right_side) / 2;

    node *root = new node(arr[mid]);

    root->left = sorted_to_BST(arr, arr_size, left_side, mid - 1);
    root->right = sorted_to_BST(arr, arr_size, mid + 1, right_side);

    return root;
}

int is_balanced(node *root, bool &ans)
{
    if (root == nullptr || ans == false)
        return 0;

    int l_height = is_balanced(root->left, ans);
    int r_height = is_balanced(root->right, ans);

    if (abs(l_height - r_height) > 1)
        ans = false;

    return max(l_height, r_height) + 1;
}

int main()
{
    srand(time(0));

    for (int alpha = 0; alpha < 10; alpha++)
    {
        int arr_size = rand() % 1000;

        int arr[arr_size] = {0};

        for (int i = 1; i < arr_size; i++)
            arr[i] = arr[i - 1] + rand() % 10;

        node *root = sorted_to_BST(arr, arr_size, 0, arr_size - 1);

        bool result = true;

        is_balanced(root, result);

        if (result)
            cout << "balanced\n";
        else
            cout << "no\n";
    }

    return 0;
}