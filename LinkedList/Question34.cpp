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

void traverse(Node *head, int n, int &num)
{

    static int diff = n;
    if (!head->next)
    {
        diff--;
        return;
    }

    traverse(head->next, n, num);
    diff--;

    if (diff == 0)
    {
        num = head->data;
    }
}

int getNthFromLast(struct Node *head, int n)
{
    int num = -1;
    traverse(head, n, num);

    return num;
}

int getNthFromLast1(Node *head, int n)
{
    Node *slow = head;
    Node *fast = head;
    for (int i = 0; i < n; i++)
    {
        if (!fast)
            return -1;
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *first = newList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);

    cout << "Number Found: " << getNthFromLast(first, 2);
    cout << "\nNumber Found: " << getNthFromLast1(first, 2);

    return 0;
}