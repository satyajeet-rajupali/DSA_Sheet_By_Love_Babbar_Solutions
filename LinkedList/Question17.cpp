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

int lengthOfList(Node *node)
{
    int count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}

Node *reverseList(Node *node)
{
    Node *p = NULL, *q = NULL;

    while (node)
    {
        q = p;
        p = node;
        node = node->next;
        p->next = q;
    }

    return p;
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

bool isPalindrome(Node *head)
{

    if (!head->next)
        return true;
    
    bool isPalindrome = false;
    Node *slow = head, *fast = head, *p = NULL;
    int le = lengthOfList(head);

    while (fast->next && fast->next->next)
    {
        p = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *temp = slow->next;
    slow->next = NULL;
    if (le % 2 != 0)
        p->next = NULL;
    if (temp->next)
    {
        temp = reverseList(temp);
    }

    while (head && temp)
    {
        if (head->data == temp->data)
        {
            isPalindrome = true;
        }
        else
        {
            isPalindrome = false;
            return isPalindrome;
        }
        head = head->next;
        temp = temp->next;
    }

    return isPalindrome;
}

int main()
{

    int arr[] = {1, 5, 2, 4, 4, 1, 2, 2, 2, 1, 5, 4, 5, 4, 2, 1};
    Node *first = newList(arr, sizeof(arr) / sizeof(arr[0]));
    display(first);

    if (isPalindrome(first))
    {
        cout << "It's Palindrome\n";
    }
    else
    {
        cout << "Not a Palindrome\n";
    }
    return 0;
}