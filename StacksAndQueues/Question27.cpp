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

queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.

    if(q.size()==1 or k >q.size()){
        return q;
    }
    queue<int> util;
    stack<int> stk;

    for (int i = 0; i < k; i++)
    {
        stk.push(q.front());
        q.pop();
    }

    while (!q.empty())
    {
        util.push(q.front());
        q.pop();
    }

    while (!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }

    while (!util.empty())
    {
        q.push(util.front());
        util.pop();
    }
    return q;
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

    q = modifyQueue(q, 3);

    display(q);

    return 0;
}