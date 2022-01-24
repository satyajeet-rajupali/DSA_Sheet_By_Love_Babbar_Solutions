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

void pairSum(Node *node, int sum1)
{
    bool isPair = false;
    Node *first = node;
    Node *second = node;
    Node *third = node;
    int sum;
    while (second->next)
        second = second->next;
    Node *tail = second;

    cout << "Triplet:\n";

    while (third)
    {
        sum = sum1 - third->data;
        second = tail;
        first = third->next;
        while (first != second && second->next != first)
        {
            if (first->data + second->data < sum)
                first = first->next;
            else if (first->data + second->data > sum)
                second = second->prev;
            else if (first->data + second->data == sum)
            {
                cout << "(" << third->data << "," << first->data << "," << second->data << ")"
                     << "\n";
                first = first->next;
                second = second->prev;
                isPair = true;
            }
        }
        third = third->next;
    }

    if (isPair == false)
        cout << "No such pair exists\n";
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6, 8, 9};
    Node *first = createList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);
    pairSum(first, 17);

    return 0;
}