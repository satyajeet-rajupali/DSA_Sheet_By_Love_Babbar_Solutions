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
    int lengthOfList(Node *node);

    int middleNode(Node *node);
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
    cout << "Middle Element: " << middleNode(head) << "\n";
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

int LinkedList::lengthOfList(Node *node)
{

    int len = 0;
    while (node)
    {
        len++;
        node = node->next;
    }
    return len;
}

int LinkedList::middleNode(Node *node)
{

    int len = lengthOfList(node);
    len = len / 2;

    while (len--)
    {
        node = node->next;
    }

    return node->data;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));
}