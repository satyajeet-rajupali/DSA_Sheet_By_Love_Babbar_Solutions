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

void FindMiddle(Node *cur, Node **first, Node **second)
{

    Node *slow = cur;
    Node *fast = cur->next;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *first = cur;
    *second = slow->next;
    slow->next = NULL;
}

Node *MergeBoth(Node *first, Node *second)
{
    Node *ans = NULL;

    if (!first)
        return second;
    else if (!second)
        return first;

    if (first->data <= second->data)
    {
        ans = first;
        ans->next = MergeBoth(first->next, second);
    }
    else
    {
        ans = second;
        ans->next = MergeBoth(first, second->next);
    }

    return ans;
}

void MergeSort(Node **head)
{
    Node *cur = *head;
    Node *first, *second;

    if (!cur || !cur->next)
        return;

    FindMiddle(cur, &first, &second);

    MergeSort(&first);
    MergeSort(&second);
    *head = MergeBoth(first, second);
}

Node *MergeSorting(Node *head)
{
    MergeSort(&head);
    return head;
}

Node *createList(int arr[], int n)
{

    Node *head = newNode(arr[0]);

    Node *last = head;

    for (int i = 1; i < n; i++)
    {
        last->next = newNode(arr[i]);
        last = last->next;
    }

    return head;
}

int main()
{
    int arr[] = {4, 9, 1, 3, 2};
    Node *head = createList(arr, sizeof(arr) / sizeof(arr[0]));
    display(head);
    Node *sortedList = MergeSorting(head);
    display(sortedList);
    return 0;
}