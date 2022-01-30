#include <bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
    if (q.empty())
        return q;
    int data = q.front();
    q.pop();

    q = rev(q);

    q.push(data);

    return q;
}

void display(queue<int> q)
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
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    display(q);
    queue<int> ans = rev(q);

    display(ans);

    return 0;
}