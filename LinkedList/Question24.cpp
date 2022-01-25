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
        cout << node->data << "<==>";
        node = node->next;
    }
    cout << "\n";
}

Node *revListInGroupOfGivenSize(Node *head, int k)
{

    if (!head)
        return NULL;
    head->prev = NULL;
    Node *temp, *curr = head, *newHead;
    int count = 0;
    while (curr != NULL && count < k)
    {
        newHead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    // checking if the reversed LinkedList size is
    // equal to K or not
    // if it is not equal to k that means we have reversed
    // the last set of size K and we don't need to call the
    // recursive function
    if (count >= k)
    {
        Node *rest = revListInGroupOfGivenSize(curr, k);
        head->next = rest;
        if (rest != NULL)
            // it is required for prev link otherwise u wont
            // be backtrack list due to broken links
            rest->prev = head;
    }
    return newHead;
}

int main()
{
    int arr[] = {3, 6, 2, 12, 56, 8};
    Node *first = createList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);

    first = revListInGroupOfGivenSize(first, 4);
    display(first);

    return 0;
}