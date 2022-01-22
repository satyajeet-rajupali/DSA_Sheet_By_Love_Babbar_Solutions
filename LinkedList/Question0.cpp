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
private:
    Node *head;

public:
    LinkedList(int arr[], int size);

    void display(Node *node);
    void iterativeReverse(Node *node);
    void recursiveReverse(Node *p, Node *node);
};

LinkedList::LinkedList(int arr[], int size)
{

    head = new Node;
    head->data = arr[0];
    head->next = NULL;

    Node *t, *p;
    p = head;

    for (int i = 1; i < size; i++)
    {

        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        p->next = t;
        p = p->next;
    }

    display(head);
    cout << "\n";
    // iterativeReverse(head);
    recursiveReverse(NULL, head);
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

void LinkedList::iterativeReverse(Node *node)
{
    Node *p = NULL, *q = NULL;

    while (node)
    {
        q = p;
        p = node;
        node = node->next;
        p->next = q;
    }
    head = p;
    cout << "After Reversal:\n";
    display(head);
}

void LinkedList::recursiveReverse(Node *p, Node *node)
{

    if (node)
    {
        recursiveReverse(node, node->next);
        node->next = p;
    }
    else
    {
        head = p;
    }
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7};
    LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}