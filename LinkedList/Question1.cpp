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
    void reverse_By_K(Node *node, int k);
};

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
    cout << "After Reverse:\n";
    reverse_By_K(head, 3);
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

void LinkedList::reverse_By_K(Node *node, int k)
{
    Node *p = NULL, *q = NULL, *s = head, *t = NULL;
    int divFac = k, flag = 0;

    while (node)
    {
        q = p;
        p = node;
        node = node->next;
        p->next = q;
        divFac--;
        if (divFac == 0)
        {
            if (flag == 0)
            {
                head = p;
                p = q = NULL;
                flag = 1;
                t = node;
                divFac = k;
            }
            else
            {
                s->next = p;
                s = t;
                t = node;
                p = q = NULL;
                divFac = k;
            }
        }
    }

    s->next = p;
    s = t;
    t = node;
    p = q = NULL;
    // head = p;

    display(head);
}

int main()
{
    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8};
    LinkedList ls = LinkedList(arr, sizeof(arr) / sizeof(arr[0]));
}