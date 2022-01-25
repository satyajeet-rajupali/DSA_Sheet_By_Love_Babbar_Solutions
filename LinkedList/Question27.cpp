#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *bottom;
    struct Node *next;
};

Node *newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    t->bottom = NULL;
    return t;
}

Node *createList(int arr[], int size)
{

    Node *head, *temp, *last;

    head = new Node;
    head->data = arr[0];
    head->bottom = NULL;
    head->next = NULL;
    last = head;

    for (int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->bottom = last;
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
        node = node->bottom;
    }
    cout << "\n";
}


Node *merge(Node *a, Node *b){

    if(!a) return b;
    if(!b) return a;

    Node *result;

    if(a->data < b->data){
        result = a;
        result ->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node *flatten(Node *root)
{

    if(!root or !root->next)
        return root;

    return merge(root, flatten(root->next));
}

int main()
{
    int arr[] = {3, 6, 2, 12, 56, 8};

    Node *head = newNode(5);
    head->bottom = newNode(7);
    head->bottom->bottom = newNode(8);
    head->bottom->bottom->bottom = newNode(30);

    head->next = newNode(10);
    head->next->bottom = newNode(20);

    head->next->next = newNode(19);
    head->next->next->bottom = newNode(22);
    head->next->next->bottom->bottom = newNode(50);

    head->next->next->next = newNode(28);
    head->next->next->next->bottom = newNode(35);
    head->next->next->next->bottom->bottom = newNode(40);
    head->next->next->next->bottom->bottom->bottom = newNode(45);

    // Node *first = createList(arr, sizeof(arr) / sizeof(arr[0]));
    // display(head);

    cout << "After Flattening:\n";
    head = flatten(head);
    display(head);

    return 0;
}