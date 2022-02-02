#include <bits/stdc++.h>
using namespace std;

void display(queue<int> q)
{
    cout << "Elements in the queue:\n";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

void interleaveQueue(queue<int> &q)
{

    if (q.size() % 2 != 0)
    {
        cout << "Input even number of elements in the queue:\n";
        return;
    }
    int halfSize = q.size() / 2;
    stack<int> stk;

    for (int i = 0; i < halfSize; i++)
    {
        stk.push(q.front());
        q.pop();
    }

    while (!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }

    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < halfSize; i++)
    {
        stk.push(q.front());
        q.pop();
    }

    while (!stk.empty())
    {
        int data = q.front();
        q.pop();
        q.push(stk.top());
        stk.pop();
        q.push(data);
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    display(q);

    interleaveQueue(q);

    display(q);
    return 0;
}