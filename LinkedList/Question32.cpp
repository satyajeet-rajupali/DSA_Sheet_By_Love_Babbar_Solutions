#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    return t;
}

void display(Node *node)
{

    cout << "Elements in the list:\n";
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

Node *newList(int arr[], int n)
{

    Node *head, *temp, *last;

    head = new Node;
    head->data = arr[0];
    head->next = NULL;

    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = last->next;
    }

    return head;
}

Node *compute(Node *head)
{
    if (!head->next)
        return head;

    Node *r = compute(head->next);
    head->next = r;

    if (head->data < r->data)
    {
        Node *d = head;
        delete d;
        return r;
    }
    else
    {
        return head;
    }
}

int main()
{
    int arr[] = {12, 15, 10, 11, 5, 6, 2, 3};
    Node *first = newList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);

    first = compute(first);
    display(first);
    return 0;
}