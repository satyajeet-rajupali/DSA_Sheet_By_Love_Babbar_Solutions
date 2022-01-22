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
public:
    Node *head;
    LinkedList(int arr[], int size);
    LinkedList(int data);
    void display(Node *node);
    Node *newNode(int data);
    Node *detectLoop(Node *node);
};

LinkedList::LinkedList(int data)
{

    head = new Node;
    head->data = data;
    head->next = NULL;
}
Node *LinkedList::newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
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

Node *LinkedList::detectLoop(Node *node)
{
    Node *t = new Node;
    Node *p = NULL;

    while (node)
    {
        p = node;
        node = node->next;
        p->next = t;

        if (node->next == t)
        {
            return node;
        }
    }

    return node;
}

int main()
{
    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8};
    LinkedList ls = LinkedList(50);

    Node *head = ls.head;
    head->next = ls.newNode(20);
    head->next->next = ls.newNode(15);
    head->next->next->next = ls.newNode(4);
    head->next->next->next->next = ls.newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    Node *ans = ls.detectLoop(head);
    if (ans)
    {
        cout << "Loop is at " << ans->data << "\n";
    }
    else
    {
        cout << "No Such Loop\n";
    }
    // LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));
}