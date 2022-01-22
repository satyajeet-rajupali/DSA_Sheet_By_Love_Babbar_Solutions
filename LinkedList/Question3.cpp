#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{

public:
    Node *head;
    LinkedList(int arr[], int size);
    LinkedList(int data);

    void display(Node *node);
    void removeLoop(Node *node);
};

LinkedList::LinkedList(int data)
{

    head = new Node;
    head->data = data;
    head->next = NULL;
}

LinkedList::LinkedList(int arr[], int size)
{

    head = new Node;
    head->data = arr[0];
    head->next = NULL;

    Node *temp, *last = head;

    for (int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = last->next;
    }

    display(head);
}

void LinkedList::display(Node *node)
{

    cout << "Elements in the list:\n";
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void LinkedList::removeLoop(Node *node)
{

    Node *p = node, *q = NULL;

    while (p)
    {
        if (p->data != -1)
        {
            q = p;
            p->data = -1;
            p = p->next;
        }
        else
        {
            q->next = NULL;
            break;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8};
    // LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));

    Node *p, *tm;

    // Initialising Head
    LinkedList ls = LinkedList(1);
    p = ls.head;
    // 1->
    // Attaching nodes
    Node *t = new Node;
    t->data = 2;
    p->next = t;
    p = p->next;
    // 1->2->
    t = new Node;
    t->data = 3;
    p->next = t;
    p = p->next;
    tm = p;

    // 1->2->3

    t = new Node;
    t->data = 4;
    p->next = t;
    p = p->next;

    t = new Node;
    t->data = 5;
    p->next = t;
    p = p->next;

    t = new Node;
    t->data = 6;
    p->next = t;
    p = p->next;
    p->next = tm;

    ls.removeLoop(ls.head);
    ls.display(ls.head);
}