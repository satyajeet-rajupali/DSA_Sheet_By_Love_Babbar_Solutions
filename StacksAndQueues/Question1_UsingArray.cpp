#include <bits/stdc++.h>
using namespace std;

class Queue
{

private:
    int front, rear, size;
    int *queue;

public:
    Queue(int arr[], int n, int sizeOfQueue);
    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    int dequeue();

    void display();
};

Queue::Queue(int arr[], int n, int sizeOfQueue)
{
    front = rear = -1;
    this->size = sizeOfQueue;
    queue = new int[sizeOfQueue];

    for (int i = 0; i < sizeOfQueue; i++)
    {
        if (i < n)
        {
            enqueue(arr[i]);
        }
        else
        {
            queue[i] = -1;
        }
    }
}

void Queue::display()
{

    if (rear == -1)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Elements in the queue:\n";
    for (int i = front + 1; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << "\n";
}

bool Queue::isEmpty()
{
    if (front == rear)
        return true;
    return false;
}

bool Queue::isFull()
{
    if (rear == (size - 1))
        return true;
    return false;
}

void Queue::enqueue(int data)
{

    if (isFull())
    {
        cout << "Queue is full\n";
        return;
    }

    rear++;
    queue[rear] = data;
}

int Queue::dequeue()
{

    int data = -1;
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        return data;
    }

    front++;
    data = queue[front];
    queue[front] = -1;

    return data;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    Queue q = Queue(arr, sizeof(arr) / sizeof(arr[0]), 10);
    q.display();

    q.enqueue(7);
    q.enqueue(8);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}