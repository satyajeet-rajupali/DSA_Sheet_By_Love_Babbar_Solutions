#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class Deque
{

private:
    Node *head, *tail;

public:
    Deque();
    Deque(int arr[], int size);

    Node *newNode(int data);
    bool isEmpty();
    bool isFull();

    void pushFront(int data);
    void pushBack(int data);

    int popBack();
    int popFront();

    void display();
};

Node *Deque::newNode(int data)
{

    Node *temp = new Node;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

Deque::Deque()
{
    head = tail = NULL;
}

Deque::Deque(int arr[], int size)
{
    head = tail = NULL;
    for (int i = 0; i < size; i++)
        pushBack(arr[i]);
}

bool Deque::isEmpty()
{
    if (head == tail)
        return true;
    return false;
}

bool Deque::isFull()
{
    Node *temp = new Node;
    if (!temp)
        return true;
    return false;
}

void Deque::pushBack(int data)
{
    if (!head)
    {
        head = newNode(data);
        tail = head;
    }
    else
    {
        Node *temp = newNode(data);
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
    }
}

void Deque::pushFront(int data)
{

    if (!tail)
    {
        head = newNode(data);
        tail = head;
    }
    else
    {
        Node *temp = newNode(data);
        temp->next = head;
        head->prev = temp;
        head = head->prev;
    }
}

int Deque::popBack()
{
    int data = -1;
    if (isEmpty())
    {
        cout << "Container is Empty\n";
        return data;
    }
    else
    {

        data = tail->data;
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    return data;
}

int Deque::popFront()
{
    int data = -1;
    if (isEmpty())
    {
        cout << "Container is Empty\n";
        return data;
    }
    else
    {
        data = head->data;
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    return data;
}

void Deque::display()
{
    if (!head)
    {
        cout << "Container Empty\n";
        return;
    }
    Node *temp = head;
    cout << "Elements in the Deque:\n";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

class Stack : public Deque
{

public:
    Stack();
    Stack(int arr[], int size);
    void push(int data);
    int pop();
};

Stack::Stack()
{
}

Stack::Stack(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        pushBack(arr[i]);
}

void Stack::push(int data)
{
    pushBack(data);
}

int Stack::pop()
{
    return popBack();
}

class Queue : public Deque
{
public:
    Queue();
    Queue(int arr[], int size);

    void enqueue(int data);
    int dequeue();
};

Queue::Queue()
{
}

Queue::Queue(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        pushBack(arr[i]);
}

void Queue::enqueue(int data)
{
    pushBack(data);
}

int Queue::dequeue()
{
    return popFront();
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    // Deque dq = Deque(arr, sizeof(arr) / sizeof(arr[0]));
    // dq.display();

    // Stack stk = Stack(arr, sizeof(arr) / sizeof(arr[0]));
    // stk.display();
    // stk.pop();
    // stk.display();
    // stk.push(7);
    // stk.display();

    Queue q = Queue(arr, sizeof(arr) / sizeof(arr[0]));
    q.display();

    q.enqueue(7);
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
