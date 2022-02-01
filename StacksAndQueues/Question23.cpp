#include <bits/stdc++.h>
using namespace std;

class KQueues
{
private:
    int free, *arr, *next, *front, *rear, k, n;

public:
    KQueues(int k, int n);
    bool isEmpty(int qn);
    bool isFull();
    void enqueue(int val, int qn);
    int dequeue(int qn);

    void display();
};

KQueues::KQueues(int k, int n)
{

    this->k = k;
    this->n = n;

    arr = new int[n];
    next = new int[n];
    front = new int[k];
    rear = new int[k];
    free = 0;
    for (int i = 0; i < this->k; i++)
        front[i] = -1;

    for (int i = 0; i < this->n - 1; i++)
        next[i] = i + 1;
    next[this->n - 1] = -1;
}

bool KQueues::isFull()
{
    return (free == n - 1);
}

bool KQueues::isEmpty(int qn)
{
    return (front[qn] == -1);
}

void KQueues::enqueue(int val, int qn)
{

    if (isFull())
    {
        cout << "Queue is FULL\n";
        return;
    }
    qn--;
    int i = free;
    free = next[i];

    if (isEmpty(qn))
        front[qn] = i;
    else
        next[rear[qn]] = i;

    next[i] = -1;
    rear[qn] = i;

    arr[i] = val;
}

int KQueues::dequeue(int qn)
{

    qn--;
    if (isEmpty(qn))
    {
        cout << "\nQueue is EMPTY\n";
        return -1;
    }

    int i = front[qn];
    front[qn] = next[i];
    next[i] = free;
    free = i;

    return arr[i];
}

void KQueues::display()
{

    for (int i = 0; i < k; i++)
    {
        cout << "Elements in Queue-" << i + 1 << ":\n";
        for (int j = front[i];; j = next[j])
        {
            if (next[j] != -1)
                cout << arr[j] << " ";
            else
            {
                cout << arr[j] << " ";
                break;
            }
        }
        cout << "\n";
    }
}

int main()
{
    KQueues kq = KQueues(3, 11);

    kq.enqueue(1, 3);
    kq.enqueue(1, 2);
    kq.enqueue(2, 2);
    kq.enqueue(2, 3);
    kq.enqueue(3, 2);
    kq.enqueue(1, 1);
    kq.enqueue(2, 1);
    kq.enqueue(3, 3);
    kq.enqueue(3, 1);

    kq.display();

    kq.dequeue(3);
    kq.dequeue(1);
    kq.dequeue(2);

    kq.display();

    kq.enqueue(4, 1);
    kq.enqueue(5, 2);
    kq.enqueue(6, 3);

    kq.display();

    return 0;
}