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

Node *addTwoLists(Node *first, Node *second)
{

    if (first->next != NULL)
        first = reverseList(first);

    if (second->next != NULL)
        second = reverseList(second);

    Node *third, *temp, *temp1;
    int sum = 0, carry = 0, flag = 0;

    cout << "Working-1\n";

    while (first && second)
    {
        if (first && second)
        {
            sum = first->data + second->data + carry;
            carry = sum / 10;
            cout << "Working-2\n";

            if (flag == 0)
            {
                third = newNode(sum % 10);
                temp = third;
                flag = 1;
                cout << "Working-3\n";
            }
            else
            {
                temp1 = newNode(sum % 10);
                temp->next = temp1;
                temp = temp->next;
                cout << "Working-4\n";
            }
        }
        first = first->next;
        second = second->next;
    }

    while (first)
    {
        sum = first->data + carry;
        carry = sum / 10;
        temp1 = newNode(sum % 10);
        temp->next = temp1;
        temp = temp->next;
        first = first->next;
        cout << "Working-5\n";
    }

    while (second)
    {
        sum = second->data + carry;
        carry = sum / 10;
        temp1 = newNode(sum % 10);
        temp->next = temp1;
        temp = temp->next;
        second = second->next;
        cout << "Working-6\n";
    }

    while (carry)
    {

        temp1 = newNode(carry % 10);
        temp->next = temp1;
        temp = temp->next;
        carry = carry / 10;
        cout << "Working-7\n";
    }

    return reverseList(third);
}

int main()
{
    Node *first = newNode(6);
    first->next = newNode(3);
    // first->next->next = newNode(9);

    Node *second = newNode(7);
    // second->next = newNode(5);

    // display(first);
    // Node *f = reverseList(first);
    // display(f);

    Node *ans = addTwoLists(first, second);
    display(ans);

    return 0;
}