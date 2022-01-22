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
    Node *addOne(Node *node);
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

    display(head);
    addOne(head);
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

Node *LinkedList::addOne(Node *head)
{

    if (head->next == NULL)
    {
        head->data += 1;
        return head;
    }

    Node *sum = addOne(head->next);
    head->data += (sum->data / 10);
    sum->data = sum->data % 10;
    return head;
}

int main()
{
    int arr[] = {9, 9, 9};
    LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));
}