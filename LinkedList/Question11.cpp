#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int lengthOfList(Node *node)
{

    int len = 0;
    while (node)
    {
        len++;
        node = node->next;
    }
    return len;
}
Node *addNewNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    return t;
}

void display(Node *node)
{

    cout << "Elements in List:\n";
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int intersectPoint(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return 0;
    Node *A = head1;
    Node *B = head2;
    while (A != B)
    {
        A = A == NULL ? head2 : A->next; // If A is NULL then shift A to head2 else do A->next
        B = B == NULL ? head1 : B->next;
    }
    return A->data; // or return B->data;
}

int main()
{
    Node *second = addNewNode(10);
    Node *first = addNewNode(3);
    first->next = addNewNode(6);
    first->next->next = addNewNode(9);
    second->next = first->next->next->next = addNewNode(15);
    first->next->next->next->next = addNewNode(30);

    cout << "First List:\n";
    display(first);

    cout << "Second List:\n";
    display(second);

    cout << "Intersection Point: " << intersectPoint(first, second) << "\n";

    return 0;
}