#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deletion(node *&head, int val)
{

    if (head != NULL && head->data == val)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node *temp = head;
    node *prev = head;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

bool search(node *head, int val)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

void list_reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *next = head->next;

    while (curr != NULL)
    {
        curr->next = prev;

        prev = curr;
        curr = next;
        if (next != NULL)
            next = next->next;
    }
    head = prev;
}

node *reverse_recursive(node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *newhead = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node *reversek(node *&head, int k)
{
    node *prev = NULL;
    node *curr = head;
    node *next;

    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr->next;
        count++;
    }

    if (next != NULL)
        head->next = reversek(next, k);

    return prev;
}

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
            startNode = temp;

        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

bool detectCycle(node *&head)
{
    node *fast = head;
    node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }

    return false;
}

void removeCycle(node *&head)
{
    node *fast = head;
    node *slow = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

node *kappend(node *&head, int k)
{
    node *new_head = head;
    node *new_tail = NULL;

    node *tail = head;
    int count = 1;
    while (count != k)
    {
        tail = tail->next;
        count++;
    }

    while (tail->next != NULL)
    {
        new_tail = new_head;
        new_head = new_head->next;
        tail = tail->next;
    }

    tail->next = head;
    new_tail->next = NULL;

    return new_head;
}

int length(node *head)
{
    int l = 0;
    node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

int detect_intersect(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;

    node *ptr1, *ptr2;

    if (l1 > l2)
    {
        d = l2 - l1;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
            return -1;
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    pos--;

    while (pos--)
        temp1 = temp1->next;

    node *temp2 = head2;
    while (temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp1;
}

node *merge(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;

    node *dummyNode = new node(-1);
    node *p3 = dummyNode;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummyNode->next;
}

node *merge_recursive(node *&head1, node *&head2)
{
    if(head1==NULL)
        return head2;

    if(head2 == NULL)
        return head2;

    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = merge_recursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merge_recursive(head1, head2->next);
    }
    return result;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {2, 3, 6};

    for (int i = 0; i < 4; i++)
        insertAtTail(head1, arr1[i]);

    for (int i = 0; i < 3; i++)
        insertAtTail(head2, arr2[i]);

    display(head1);
    display(head2);

    node *newHead = merge_recursive(head1, head2);
    display(newHead);
    return 0;
}