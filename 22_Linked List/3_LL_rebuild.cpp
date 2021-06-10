#include <iostream>
using namespace std;

class LL
{
    struct node
    {
        int val;
        node *next;
    };
    node *start;

    node *make_new_node(const int data)
    {
        node *new_node = new node;

        if (new_node == NULL)
            return NULL;

        new_node->val = data;
        new_node->next = NULL;

        return new_node;
    }

public:
    LL() : start(NULL) {}

    LL(int data)
    {
        node *temp = new node;

        temp->val = data;
        temp->next = NULL;
    }

    u_int return_list_length();
    bool insert_start(const int data);
    bool insert_end(const int data);
    bool insert_sorted(const int data);
    void display();
    void append_last_k_start(int k);

    void intersect(LL list, const int pos);
    int detect_intersect(LL list);

    void merge_two_sorted_LL(LL list);
};

u_int LL::return_list_length()
{
    u_int len = 0;

    node *iter = start;

    while (iter != NULL)
    {
        len++;
        iter = iter->next;
    }

    return len;
}

bool LL::insert_start(const int data)
{
    node *temp = make_new_node(data);

    if (start == NULL)
        start = temp;
    else
    {
        temp->next = start;
        start = temp;
    }

    return true;
}

bool LL::insert_end(const int data)
{

    node *new_node = make_new_node(data);

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        node *iter = start;

        while (iter->next != NULL)
            iter = iter->next;

        iter->next = new_node;
    }

    return true;
}

bool LL::insert_sorted(const int data)
{
    node *new_node = make_new_node(data);

    if (start == NULL)
        start = new_node;
    else if (start->next == NULL)
    {
        if (start->val > new_node->val)
        {
            new_node->next = start;
            start = new_node;
        }
        else
        {
            start->next = new_node;
        }
    }
    else
    {
        if (start->val > new_node->val)
        {
            new_node->next = start;
            start = new_node;
        }
        else
        {
            node *iter = start;

            while (iter->next != NULL && !(iter->val <= new_node->val && iter->next->val > new_node->val))
                iter = iter->next;

            new_node->next = iter->next;

            iter->next = new_node;
        }
    }

    return true;
}

void LL::display()
{
    node *temp = start;

    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }

    cout << "NULL\n";

    // cout << "List Length: " << return_list_length() << "\n";
}

void LL::append_last_k_start(const int k)
{
    node *front = start;

    for (int i = 0; i < k; i++)
    {
        if (front == NULL)
            return;

        front = front->next;
    }

    if (front == NULL)
        return;

    node *back = start;

    while (front->next != NULL)
    {
        front = front->next;
        back = back->next;
    }

    front->next = start;
    start = back->next;
    back->next = NULL;
}

void LL::intersect(LL list, const int pos)
{
    node *temp1 = start;
    int counter = 1;

    while (temp1->next != NULL && counter != pos)
    {
        temp1 = temp1->next;
        counter++;
    }

    node *temp2 = list.start;

    while (temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp1;
}

int LL::detect_intersect(LL list)
{
    u_int len1 = return_list_length();
    u_int len2 = list.return_list_length();

    node *longer, *shorter;
    u_int diff;

    if (len1 > len2)
    {
        longer = start;
        shorter = list.start;
        diff = len1 - len2;
    }
    else
    {
        longer = list.start;
        shorter = start;
        diff = len2 - len1;
    }

    for (int i = 0; i < diff; i++)
        longer = longer->next;

    while (longer->next != NULL && shorter->next != NULL)
    {
        if (longer->next == shorter->next)
            return longer->next->val;

        longer = longer->next;
        shorter = shorter->next;
    }
    return -1;
}

void LL::merge_two_sorted_LL(LL list)
{
    node *it1 = start;
    node *it2 = list.start;

    node *new_start = NULL;
    node *new_start_it = NULL;

    while (it1 != NULL && it2 != NULL)
    {
        if (it1->val < it2->val)
        {
            if (new_start == NULL)
            {
                new_start = it1;
                new_start_it = it1;
            }
            else
            {
                new_start_it->next = it1;
                new_start_it = new_start_it->next;
            }
            it1 = it1->next;
        }
        else
        {
            node *new_node = make_new_node(it2->val);
            if (new_start == NULL)
            {
                new_start = new_node;
                new_start_it = new_node;
            }
            else
            {
                new_start_it->next = new_node;
                new_start_it = new_start_it->next;
            }
            it2 = it2->next;
        }
    }

    while (it1 != NULL)
    {
        if (new_start == NULL)
        {
            new_start = it1;
            new_start_it = it1;
        }
        else
        {
            new_start_it->next = it1;
            new_start_it = new_start_it->next;
        }
        it1 = it1->next;
    }

    while (it2 != NULL)
    {
        node *new_node = make_new_node(it2->val);
        if (new_start == NULL)
        {
            new_start = new_node;
            new_start_it = new_node;
        }
        else
        {
            new_start_it->next = new_node;
            new_start_it = new_start_it->next;
        }
        it2 = it2->next;
    }

    start = new_start;
}

int main()
{
    LL list1;
    list1.insert_sorted(1);
    list1.insert_sorted(4);
    list1.insert_sorted(5);
    list1.insert_sorted(7);
    list1.display();

    LL list2;
    list2.insert_sorted(2);
    list2.insert_sorted(3);
    list2.insert_sorted(6);
    list2.display();

    list1.merge_two_sorted_LL(list2);
    list1.display();
    list2.display();

    return 0;
}