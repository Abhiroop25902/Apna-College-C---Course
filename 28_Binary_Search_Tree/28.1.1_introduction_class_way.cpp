#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BST
{
    struct node
    {
        T data;
        node *left;
        node *right;

        node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    node *root;
    void preorder(node *n);
    void inorder(node *n);
    void postorder(node *n);
    bool search(const T &key, node *&par, node *&loc);

public:
    BST() : root(nullptr) {}

    void display_preorder()
    {
        preorder(root);
        cout << endl;
    }
    void display_inorder()
    {
        inorder(root);
        cout << endl;
    }
    void display_postorder()
    {
        postorder(root);
        cout << endl;
    }
    void display_levelorder();
    bool search_for_ele(const T &key)
    {
        node *loc;
        node *par;
        return search(key, par, loc);
    }
    bool insert(const T &data);
};

template <typename T>
void BST<T>::preorder(node *n)
{
    if (n != nullptr)
    {
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }
}

template <typename T>
void BST<T>::inorder(node *n)
{
    if (n != nullptr)
    {
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
}

template <typename T>
void BST<T>::postorder(node *n)
{
    if (n != nullptr)
    {
        postorder(n->left);
        postorder(n->right);
        cout << n->data << " ";
    }
}

template <typename T>
void BST<T>::display_levelorder()
{
    queue<node *> q;
    q.push(root);
    int q_size;
    node *temp;

    while (!q.empty())
    {
        q_size = q.size();

        for (int i = 0; i < q_size; i++)
        {
            temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }

        cout << "\n";
    }
}

template <typename T>
bool BST<T>::search(const T &key, node *&par, node *&loc)
{
    if (root == nullptr)
        return false;

    node *curr = root;
    node *save = nullptr;

    while (curr != nullptr)
    {
        if (curr->data == key)
        {
            loc = curr;
            par = save;
            return true;
        }
        else if (curr->data > key)
        {
            save = curr;
            curr = curr->left;
        }
        else if (curr->data < key)
        {
            save = curr;
            curr = curr->right;
        }
    }

    //this signifies element has not been found
    loc = nullptr;
    par = save;
    return false;

    /*
        end result:
        1)  loc = null; par = null (assuming assigned null at declaration) -> tree empty
        2)  loc = null; par!= null ->element not found, par is in a leaf node
        3)  loc!= null; par = null -> root node
        4)  loc!= null; par!= null -> element found
    */
}

template <typename T>
bool BST<T>::insert(const T &data)
{
    node *par = nullptr;
    node *loc = nullptr;
    search(data, par, loc);

    if (loc != nullptr)
    {
        cout << "Element already exists";
        return false;
    }
    else
    {
        node *new_node = new node(data);

        if (root == nullptr)
            root = new_node;
        else
        {
            if (par->data > data)
            {
                par->left = new_node;
                return true;
            }
            else
            {
                par->right = new_node;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    BST<int> b;

    int arr[6] = {5, 1, 3, 4, 2, 7};

    for (int i = 0; i < 6; i++)
        b.insert(arr[i]);

    b.display_levelorder();
}
