#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{

private:
    struct Node *top;

public:
    Stack(int arr[], int data);
    Node *newNode(int data);

    bool isEmpty();
    bool isFull();

    void push(int data);
    int pop();

    int peek(int index);
    int stackTop();

    void display();
};

Node *Stack::newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->next = NULL;
    return t;
}

Stack::Stack(int arr[], int size)
{
    top = newNode(arr[size - 1]);

    Node *last = top;

    for (int i = size - 2; i >= 0; i--)
    {
        last->next = newNode(arr[i]);
        last = last->next;
    }
}

void Stack::display()
{

    Node *p = top;

    if (!top)
    {
        cout << "Stack is Empty\n";
        return;
    }

    cout << "Elements in the stack:\n";
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

bool Stack::isEmpty()
{
    if (!top)
        return true;
    return false;
}

bool Stack::isFull()
{
    Node *t = new Node;
    if (!t)
        return true;
    return false;
}

void Stack::push(int data)
{

    if (isFull())
    {
        cout << "Stack Overflow\n";
        return;
    }

    Node *temp = newNode(data);
    temp->next = top;
    top = temp;
}

int Stack::pop()
{
    int data = -1;
    if (isEmpty())
    {
        cout << "Stack Underflow\n";
        return data;
    }

    Node *temp = top;
    top = top->next;
    temp->next = NULL;
    data = temp->data;
    delete temp;
    return data;
}

int Stack::peek(int index)
{

    if (!top)
    {
        cout << "Stack Empty\n";
        return -1;
    }

    Node *p = top;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    if (!p)
    {
        cout << "No such element exists.\n";
        return -1;
    }
    return p->data;
}

int Stack::stackTop()
{

    if (!top)
    {
        cout << "Stack is Empty\n";
        return -1;
    }
    return top->data;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    Stack stk = Stack(arr, sizeof(arr) / sizeof(arr[0]));
    stk.display();

    stk.push(10);
    stk.push(9);
    stk.display();

    stk.pop();

    stk.display();

    cout << "Element at top: " << stk.stackTop() << "\n";
    cout << "Element at 2: " << stk.peek(2) << "\n";
    cout << "Element at 4: " << stk.peek(4) << "\n";
    cout << "Element at 7: " << stk.peek(7) << "\n";

    return 0;
}
