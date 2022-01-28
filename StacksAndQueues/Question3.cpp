#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *newNode(int data)
{
    Node *t = new Node;
    t->data = data;
    t->prev = NULL;
    t->next = NULL;
    return t;
}

class Stack
{

private:
    Node *top;
    Node *mid;
    int size;

public:
    Stack();

    void push(int data);
    int pop();
    bool isEmpty();
    bool isFull();
    int findMiddle();
    void display();
    int deleteMiddle();
};

Stack::Stack()
{

    int data = -1;
    top = NULL;
    mid = NULL;
    size = 0;
}

bool Stack::isFull()
{

    Node *t = new Node;
    if (!t)
        return true;
    return false;
}

bool Stack::isEmpty()
{

    if (!top)
        return true;
    return false;
}

void Stack::push(int data)
{
    if (isFull())
    {
        cout << "Stack Overflow\n";
    }
    if (!top)
    {
        top = newNode(data);
        mid = top;

        size++;
    }
    else
    {
        Node *temp = newNode(data);
        temp->next = top;
        top->prev = temp;
        top = temp;
        size++;
        if (size % 2 == 0)
        {
            mid = mid->prev;
        }
    }
}

int Stack::findMiddle()
{

    if (size == 0)
    {
        return -1;
    }
    return mid->data;
}

void Stack::display()
{

    cout << "Elements in the stack:\n";
    Node *temp = top;
    while (temp)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

int Stack::pop()
{
    int data = -1;
    if (size == 0)
    {
        return data;
    }

    Node *temp = top;
    top = top->next;
    temp->next = NULL;
    top->prev = NULL;

    if (size % 2 == 0)
    {
        mid = mid->next;
    }
    size--;

    data = temp->data;
    delete temp;

    return data;
}

int Stack::deleteMiddle()
{

    int data = -1;
    if (size == 0)
    {
        return data;
    }

    Node *temp = mid;

    if (size % 2 == 0)
    {
        mid = mid->next;
        mid->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        data = temp->data;
    }
    else
    {
        mid = mid->prev;
        temp->next->prev = temp->prev;
        mid->next = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        data = temp->data;
    }
    size--;
    delete temp;
    return data;
}

int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);

    stk.display();
    cout << "Middle Element: " << stk.findMiddle() << "\n";

    

    stk.deleteMiddle();
    stk.display();
    cout << "Middle Element: " << stk.findMiddle() << "\n";

    return 0;
}