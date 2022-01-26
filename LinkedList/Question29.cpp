#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *arb;
};

Node *newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    t->arb = NULL;
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

Node *copyList(Node *head)
{
    Node *p = head;
    Node *temp;

    while (p)
    {
        temp = p->next;
        p->next = newNode(p->data);
        p->next->next = temp;
        p = temp;
    }

    p = head;

    while (p)
    {
        p->next->arb = p->arb ? p->arb->next : p->arb;
        p = p->next->next;
    }

    Node *original = head, *copy = head->next;
    temp = copy;

    while (original and copy)
    {
        original->next = original->next->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}

int main()
{
    

    return 0;
}