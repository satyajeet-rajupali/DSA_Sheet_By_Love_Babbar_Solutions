#include <bits/stdc++.h>
using namespace std;

class QueueStacks
{

public:
    stack<int> s1;
    stack<int> s2;

    void push(int data);
    int pop();

    void display(stack<int> stk);
};

void QueueStacks::push(int data)
{
    s1.push(data);
}

int QueueStacks::pop()
{

    if (s1.empty())
        return -1;

    while (s1.size() != 1)
    {
        s2.push(s1.top());
        s1.pop();
    }
    int data = s1.top();
    s1.pop();

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    return data;
}

void QueueStacks::display(stack<int> stk)
{

    if (stk.empty())
        return;
    int data = stk.top();
    stk.pop();
    display(stk);
    cout << data << " ";
}

int main()
{
    QueueStacks qs;
    qs.s1.push(1);
    qs.s1.push(2);
    qs.s1.push(3);
    qs.s1.push(4);
    qs.s1.push(5);

    cout << "Elements in the queu:\n";
    qs.display(qs.s1);
    cout << "\n";

    qs.pop();

    cout << "Elements in the queu:\n";
    qs.display(qs.s1);
    cout << "\n";

    qs.pop();

    cout << "Elements in the queu:\n";
    qs.display(qs.s1);
    cout << "\n";

    qs.s1.push(6);
    qs.s1.push(7);
    cout << "Elements in the queu:\n";
    qs.display(qs.s1);
    cout << "\n";

    qs.pop();

    cout << "Elements in the queu:\n";
    qs.display(qs.s1);
    cout << "\n";

    return 0;
}