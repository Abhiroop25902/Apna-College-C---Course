#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int a)
    {
        data = a;
        next = NULL;
        prev = NULL;
    }
};

void insert_head(node *&head, int val)
{
    node *new_node = new node(val);

    new_node->next = head;

    if (head != NULL)
        head->prev = new_node;

    head = new_node;
}

void insert_tail(node *&head, int val)
{

    if (head == NULL)
    {
        insert_head(head, val);
        return;
    }

    node *new_node = new node(val);

    node *iterator = head;

    while (iterator->next != NULL)
        iterator = iterator->next;

    iterator->next = new_node;
    new_node->prev = iterator;
}

void display(node *head)
{
    node *iter = head;
    while (iter != NULL)
    {
        cout << iter->data << "->";
        iter = iter->next;
    }
    cout << "NULL\n";
}

void delete_head(node *&head)
{
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        delete_head(head);
        return;
    }
    int i = 1;
    node *iter = head;

    while (i < pos && iter != NULL)
    {
        i++;
        iter = iter->next;
    }

    iter->prev->next = iter->next;

    if (iter->next != NULL)
        iter->next->prev = iter->prev;

    delete iter;
}

int main()
{
    node *head = NULL;
    
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    display(head);
    insert_head(head, 5);
    display(head);
    deletion(head, 1);
    display(head);

    return 0;
}