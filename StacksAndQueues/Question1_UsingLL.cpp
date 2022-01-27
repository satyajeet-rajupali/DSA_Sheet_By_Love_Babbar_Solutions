#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front, *rear, *queue;

public:
    Node *newNode(int data);
    Queue(int arr[], int size);
    bool isFull();
    bool isEmpty();
    void enqueue(int data);
    int dequeue();
    void display();
};

Node *Queue::newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Queue::Queue(int arr[], int size)
{
    front = NULL, rear = NULL;
    for (int i = 0; i < size; i++)
        enqueue(arr[i]);
}

bool Queue::isEmpty()
{
    if (!rear)
        return true;
    return false;
}

bool Queue::isFull()
{
    Node *t = new Node;
    if (!t)
        return true;
    return false;
}

void Queue::enqueue(int data)
{

    if (isFull())
    {
        cout << "Queue is Full\n";
        return;
    }

    if (!front)
    {
        queue = newNode(data);
        front = rear = queue;
    }
    else
    {
        rear->next = newNode(data);
        rear = rear->next;
    }
}

int Queue::dequeue()
{

    int data = -1;
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        return data;
    }

    Node *temp = front;
    front = front->next;
    temp->next = NULL;
    data = temp->data;
    delete temp;
    return data;
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Stack is Empty\n";
        return;
    }

    cout << "Elements in queue:\n";
    Node *p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    Queue q = Queue(arr, sizeof(arr) / sizeof(arr[0]));
    q.display();

    q.enqueue(7);
    q.enqueue(8);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}