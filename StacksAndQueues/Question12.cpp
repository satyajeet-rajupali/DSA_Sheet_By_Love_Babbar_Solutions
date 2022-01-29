#include <bits/stdc++.h>
using namespace std;

void display(stack<int> stk)
{
    cout << "Elements in the stack:\n";
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";
}

void insertAtBottom(stack<int> &stk, int element)
{
    if (stk.empty())
    {
        stk.push(element);
        return;
    }
    int data = stk.top();
    stk.pop();
    insertAtBottom(stk, element);
    stk.push(data);
}

int main()
{
    stack<int> stk;
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    display(stk);

    insertAtBottom(stk, 1);
    display(stk);

    return 0;
}