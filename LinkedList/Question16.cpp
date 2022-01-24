#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    struct Node *next;
};

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

    last->next = head;
    return head;
}

void splitList(Node *head, Node **headref1, Node **headref2)
{

    Node *slow = head;
    Node *fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *headref1 = head;
    *headref2 = slow->next;
    slow->next = *headref1;

    if (fast->next == head)
    {
        fast->next = *headref2;
    }
    else if (fast->next->next == head)
    {
        fast->next->next = *headref2;
    }
}

void display1(Node *node)
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

int main()
{
    int arr[] = {3, 4, 5, 6, 7};
    Node *first = newList(arr, sizeof(arr) / sizeof(arr[0]));
    display1(first);

    Node *firstHalf = NULL, *secondHalf = NULL;
    splitList(first, &firstHalf, &secondHalf);
    cout << "First Half:\n";
    display1(firstHalf);

    cout << "Second Half:\n";
    display1(secondHalf);

    return 0;
}