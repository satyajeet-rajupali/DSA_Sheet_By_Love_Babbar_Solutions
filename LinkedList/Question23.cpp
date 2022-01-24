#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

Node *createList(int arr[], int size)
{

    Node *head, *temp, *last;

    head = new Node;
    head->data = arr[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;

    for (int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->prev = last;
        temp->next = NULL;
        last->next = temp;
        last = last->next;
    }
    return head;
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

void rotateByN(Node **head, int n)
{
    if (n > 0)
    {
        Node *temp = *head, *p = *head;

        while (n--)
            temp = temp->next;
        temp->prev->next = NULL;
        temp->prev = NULL;

        *head = temp;
        while (temp->next)
            temp = temp->next;

        temp->next = p;
        p->prev = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    Node *first = createList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);
    rotateByN(&first, 0);
    display(first);
    return 0;
}