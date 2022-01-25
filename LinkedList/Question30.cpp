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

Node *Merge(Node *a, Node *b)
{

    if (!a)
        return b;
    if (!b)
        return a;

    Node *result;

    if (a->data < b->data)
    {
        result = a;
        result->next = Merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = Merge(a, b->next);
    }
   
    return result;
}

Node *mergeKLists(Node *arr[], int K)
{
    Node *head = NULL;
    for (int i = 0; i < K; i++)
    {
        head = Merge(head, arr[i]);
        // display(head);
    }
    return head;
}

int main()
{

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arr3[] = {5, 6};
    int arr4[] = {7, 8};

    Node *first = newList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    // display(first);

    Node *second = newList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    // display(second);

    Node *third = newList(arr3, sizeof(arr3) / sizeof(arr3[0]));
    // display(third);

    Node *fourth = newList(arr4, sizeof(arr4) / sizeof(arr4[0]));
    // display(fourth);

    Node *arr[] = {first, second, third, fourth};

    // for(int i=0; i<4; i++){
    //     display(arr[i]);
    // }

    Node *head = mergeKLists(arr, 4);
    display(head);

    return 0;
}