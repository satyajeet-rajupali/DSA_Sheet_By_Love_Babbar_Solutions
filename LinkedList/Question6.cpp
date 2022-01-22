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
    void removeDuplicatesUnsorted(Node *node);
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
    cout << "Before Removal:\n";
    display(head);
    removeDuplicatesUnsorted(head);
    cout << "After Removal:\n";
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

void LinkedList::removeDuplicatesUnsorted(Node *node)
{

    unordered_map<int, int> mp;
    Node *p = node;
    mp[p->data] = 1;
    Node *q = node->next;
    while (q)
    {
        if (mp.find(q->data) != mp.end())
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            mp[p->data] = 1;
            p = q;
            q = q->next;
        }
    }
}

int main()
{
    int arr[] = {2, 2, 2, 2, 2};
    LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));
}