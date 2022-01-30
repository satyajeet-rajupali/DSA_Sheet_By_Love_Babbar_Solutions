#include <bits/stdc++.h>
using namespace std;

class QueueStack
{

public:
    queue<int> q1, q2;
    void push(int data);
    int pop();
    void display(queue<int> q);
};

void QueueStack::push(int data)
{

    q1.push(data);
}

int QueueStack::pop()
{

    if (q1.empty())
        return -1;

    int data = q1.back();

    while (q1.size() != 1)
    {

        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();
    swap(q2, q1);

    return data;
}

void QueueStack::display(queue<int> q)
{

    cout << "Elements in the stack:\n";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main()
{
    QueueStack qs;
    qs.push(1);
    qs.push(2);
    qs.push(3);

    qs.display(qs.q1);

    qs.pop();
    qs.display(qs.q1);

    qs.pop();

    qs.display(qs.q1);

    qs.push(4);

    qs.display(qs.q1);

    return 0;
}