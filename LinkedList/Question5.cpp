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
    Node *newNode(int data);
    void removeDuplicates(Node *node);
};

Node *LinkedList::newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void LinkedList::removeDuplicates(Node *node)
{

    Node *p = node->next;
    while (p)
    {
        if (p->data != node->data)
        {
            node = p;
            p = p->next;
        }
        else
        {
            node->next = p->next;
            delete p;
            p = node->next;
        }
    }

    cout << "Duplicates Removed Successfully\n";
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
    cout << "Before:\n";
    display(head);
    removeDuplicates(head);
    cout << "After\n";
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

int main()
{
    int arr[] = {2, 2, 4, 5};
    LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));
}