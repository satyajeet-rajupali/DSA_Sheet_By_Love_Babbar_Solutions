#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct compare
{
    bool operator()(struct Node *p1, struct Node *p2)
    {
        return p1->data > p2->data;
    }
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

// Insertion Sort: TC: O(k*n)
Node *sortAKSortedDLL(Node *head, int k)
{
    if (!head || !head->next)
        return head;

    for (Node *i = head->next; i != NULL; i = i->next)
    {
        Node *j = i;

        while (j->prev && j->data < j->prev->data)
        {
            Node *temp = j->prev->prev;
            Node *temp2 = j->prev;
            Node *temp3 = j->next;
            j->prev->next = j->next;
            j->prev->prev = j;
            j->prev = temp;
            j->next = temp2;

            if (temp)
                temp->next = j;

            if (temp3)
                temp3->prev = temp2;
        }

        if (!j->prev)
            head = j;
    }

    return head;
}

Node *SortAKSortedDLL(Node *head, int k)
{

    if (!head || !head->next)
        return head;

    priority_queue<int, vector<Node *>, compare> pq;

    Node *newHead = NULL, *last;

    for (int i = 0; i <= k && head != NULL; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while (!pq.empty())
    {
        if (!newHead)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
        else
        {

            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }

        pq.pop();

        if (head)
        {
            pq.push(head);
            head = head->next;
        }
    }

    last->next = NULL;

    return newHead;
}

int main()
{
    int arr[] = {3, 6, 2, 12, 56, 8};
    Node *first = createList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);

    // first = sortAKSortedDLL(first, 2);
    // display(first);

    first = SortAKSortedDLL(first, 2);
    display(first);

    return 0;
}