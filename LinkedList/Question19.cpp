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

Node *reverse(Node *head)
{

    Node *tail = head;

    while (tail->next != NULL)
    {
        swap(tail->prev, tail->next);
        tail = tail->prev;
    }
    head = tail;
    swap(head->next, head->prev);
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

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    Node *first = createList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);

    cout << "After reversal:\n";
    first = reverse(first);
    display(first);

    return 0;
}