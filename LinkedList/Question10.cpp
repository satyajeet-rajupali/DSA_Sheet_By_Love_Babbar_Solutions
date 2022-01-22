#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *addNewNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    return t;
}

Node *findIntersection(Node *first, Node *second)
{

    Node *third, *temp, *temp1;
    int flag = 0;
    while (first && second)
    {
        /* code */
        if (first->data < second->data)
        {
            first = first->next;
        }
        else if (first->data > second->data)
        {
            second = second->next;
        }
        else if (first->data == second->data)
        {
            if (flag == 0)
            {
                third = addNewNode(first->data);
                temp = third;
                flag = 1;
            }
            else
            {
                temp1 = addNewNode(first->data);
                temp->next = temp1;
                temp = temp->next;
            }
            first = first->next;
            second = second->next;
        }
    }

    return third;
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

int main()
{
    // 1->2->3->4->6
    Node *first = addNewNode(10);
    first->next = addNewNode(20);
    first->next->next = addNewNode(40);
    first->next->next->next = addNewNode(50);
    // first->next->next->next->next = addNewNode(6);
    display(first);
    // 2->4->6->8

    Node *second = addNewNode(15);
    second->next = addNewNode(40);
    // second->next->next = addNewNode(6);
    // second->next->next->next = addNewNode(8);
    display(second);

    Node *res = findIntersection(first, second);
    display(res);

    return 0;
}