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

Node *divide(Node *head)
{

    if (!head || !head->next)
        return head;

    Node *o = NULL, *e = NULL, *le = NULL, *lo = NULL;
    int fe = 0, fo = 0;

    while (head)
    {
        if (head->data % 2 == 0)
        {
            if (fe == 0)
            {
                e = head;
                le = e;
                fe = 1;
            }
            else
            {
                le->next = head;
                le = le->next;
            }
        }
        else
        {
            if (fo == 0)
            {
                o = head;
                lo = o;
                fo = 1;
            }
            else
            {
                lo->next = head;
                lo = lo->next;
            }
        }

        head = head->next;
    }

    if (e && o)
    {
        le->next = o;
        lo->next = NULL;
        return e;
    }
    else if (!e && o)
    {
        return o;
    }
    else if (e && !o)
    {
        return e;
    }
    return head;
}

int main()
{
    int arr[] = {2, 4, 6};
    Node *first = newList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);

    first = divide(first);
    display(first);
    return 0;
}