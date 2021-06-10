#include <iostream>
using namespace std;

class CircularLL
{
    struct node
    {
        int data;
        node *next;
    };

    node *start;

    node *make_new_node(const int val)
    {
        node *new_node = new node;
        new_node->data = val;
        new_node->next = NULL;

        return new_node;
    }

public:
    CircularLL()
    {
        start = new node;
        start->data = -1;
        start->next = start;
    }

    void insert_head(const int val);
    void insert_tail(const int val);
    void displayCLL();
    bool delete_node(const int val);
    bool delete_at_head();
};

void CircularLL::insert_head(const int val)
{
    node *new_node = make_new_node(val);

    new_node->next = start->next;
    start->next = new_node;
}

void CircularLL::insert_tail(const int val)
{
    node *new_node = make_new_node(val);

    node *it = start;

    while (it->next != start)
        it = it->next;

    new_node->next = it->next;
    it->next = new_node;
}

void CircularLL::displayCLL()
{
    node *iter = start->next;

    while (iter != start)
    {
        cout << iter->data << "->";
        iter = iter->next;
    }

    cout << "LOOP\n";
}

bool CircularLL::delete_node(const int val)
{
    node *iter = start->next;
    node *prev = start;

    if (start->next == start)
        return false;
    else
        while (iter != start)
        {
            if (iter->data == val)
            {
                prev->next = iter->next;
                delete iter;
                return true;
            }

            prev = iter;
            iter = iter->next;
        }
    return false;
}

bool CircularLL::delete_at_head()
{
    if (start->next == start)
        return false;

    node *node_to_delete = start->next;

    start->next = node_to_delete->next;
    delete node_to_delete;

    return false;
}

int main()
{
    CircularLL l1;

    l1.insert_tail(1);
    l1.insert_tail(2);
    l1.insert_tail(3);
    l1.insert_tail(4);
    l1.insert_head(5);
    l1.displayCLL();

    l1.delete_at_head();
    l1.displayCLL();

    return 0;
}
