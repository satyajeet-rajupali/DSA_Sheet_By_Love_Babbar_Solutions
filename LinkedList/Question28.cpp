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

Node *segregate(Node *head)
{

    Node *temp = head;

    int zero = 0, one = 0, two = 0;

    while (temp)
    {
        switch (temp->data)
        {
        case 0:
            zero++;
            break;
        case 1:
            one++;
            break;
        case 2:
            two++;
            break;
        default:
            break;
        }
        temp = temp->next;
    }
    temp = head;

    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }

    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }

    return head;
}

int main()
{

    int arr[] = {1, 2, 2, 1, 2, 0, 2, 2};
    Node *first = newList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);

    cout<<"After Segregation:\n";
    first = segregate(first);
    display(first);

    return 0;
}