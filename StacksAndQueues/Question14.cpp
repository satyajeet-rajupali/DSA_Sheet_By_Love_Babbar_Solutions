#include <bits/stdc++.h>
using namespace std;

class SortedStack
{

public:
    stack<int> stk;
    void sort();
};

void sortedInsert(stack<int> &stk, int element)
{
    if (stk.empty() or element > stk.top())
    {
        stk.push(element);
        return;
    }

    int temp = stk.top();
    stk.pop();
    sortedInsert(stk, element);
    stk.push(temp);
}

void SortedStack::sort()
{
    if (!stk.empty())
    {
        int element = stk.top();
        stk.pop();
        sort();
        sortedInsert(stk, element);
    }
    return;
}

void display(stack<int> stk)
{
    cout << "Elements in the stack:\n";
    while (!stk.empty())
    {
        cout << stk.top() << "\n";
        stk.pop();
    }
}

int main()
{
    SortedStack sr;
    sr.stk.push(41);
    sr.stk.push(3);
    sr.stk.push(32);
    sr.stk.push(2);
    sr.stk.push(11);

    cout << "Before Sorting:\n";
    display(sr.stk);

    sr.sort();

    cout << "After Sorting:\n";
    display(sr.stk);

    return 0;
}