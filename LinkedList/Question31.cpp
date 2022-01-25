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

long long multiplyTwoLists(Node *l1, Node *l2)
{

    long long mod = 1000000007;
    long long x = 0L;
    long long y = 0L;

    while (l1)
    {
        x = ((x * 10) + l1->data) % mod;
        l1 = l1->next;
    }

    while (l2)
    {
        y = ((y * 10) + l2->data) % mod;
        l2 = l2->next;
    }

    return (x * y) % mod;
}

int main()
{

    int arr1[] = {3, 2};
    int arr2[] = {2};

    Node *first = newList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    display(first);

    Node *second = newList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    display(second);

    cout << "Product: " << multiplyTwoLists(first, second) << "\n";

    return 0;
}