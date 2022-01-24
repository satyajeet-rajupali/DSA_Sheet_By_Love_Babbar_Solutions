#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *createList(int arr[], int size)
{

    Node *head, *temp, *last;

    head = new Node;
    head->data = arr[0];
    head->next = NULL;

    last = head;

    for (int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = last->next;
    }

    last->next = head;

    return head;
}

void display(Node *node)
{

    Node *head = node;
    cout << "Elements in the list:\n";
    do
    {
        cout << node->data << " ";
        node = node->next;
    } while (node != head);
    cout << "\n";
}

void deleteNode(Node **head, int key)
{
    Node *t = *head;
    int dat = -1;
    // Deleting head Node
    if (t->data == key)
    {
        while (t->next != *head)
            t = t->next;

        Node *temp = *head;
        t->next = temp->next;
        *head = temp->next;
        temp->next = NULL;
        dat = temp->data;
        delete temp;
    }
    // Deleting other node
    else
    {
        Node *p = NULL;
        while (t->next != *head)
        {
            if (t->data == key)
            {
                dat = 0;
                break;
            }
            p = t;
            t = t->next;
        }
        if (dat != -1)
        {
            p->next = t->next;
            t->next = NULL;
            dat = t->data;
            delete t;
        }
    }
    if (dat != -1)
        cout << "Value Deleted Successfully!\n";
    else
        cout << "No such value exist\n";
}

int main()
{
    int arr[] = {1,
                 2,
                 3,
                 4,
                 5,
                 6};
    Node *first = createList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);
    deleteNode(&first, 7);
    display(first);

    return 0;
}