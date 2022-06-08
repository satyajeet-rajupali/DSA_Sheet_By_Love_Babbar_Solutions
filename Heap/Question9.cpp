#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to merge K sorted linked list.
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
        // Your code here
        Node *head = NULL;
        for (int i = 0; i < K; i++)
        {
            head = Merge(head, arr[i]);
            // display(head);
        }
        return head;
    }
};
