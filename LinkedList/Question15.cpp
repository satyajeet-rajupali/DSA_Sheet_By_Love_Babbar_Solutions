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
    bool isCircular(Node *node);
};

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

    last->next = head;

    if (isCircular(head))
    {
        cout << "Circular Linked List\n";
    }
    else
    {
        cout << "Not Circular Linked List\n";
    }

    // display(head);
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

bool LinkedList::isCircular(Node *node)
{

    while (node)
    {
        if (node->next == head)
            return true;
    }

    return false;
}

int main()
{
    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8};
    LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));
}