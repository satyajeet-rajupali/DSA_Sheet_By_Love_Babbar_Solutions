#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int> &s, stack<int> &r)
{

    if (s.empty())
    {
        return;
    }
    r.push(s.top());
    s.pop();

    reverse(s, r);
}

void display(stack<int> s)
{
    cout << "\nElements in the stack:\n";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s, r;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    display(s);

    reverse(s, r);

    display(r);

    return 0;
}