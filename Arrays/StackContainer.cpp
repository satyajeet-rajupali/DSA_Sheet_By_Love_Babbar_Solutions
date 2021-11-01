#include <iostream>
#include <stack>

using namespace std;

void showStack(stack<int> stk)
{

    cout << "Elements in the stack(Using empty() as a factor):\n";
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

void showStackUsingSize(stack<int> stk)
{

    cout << "Elements in the stack(Using size() as a factor):\n";
    while (stk.size() > 0)
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main()
{

    stack<int> stk;

    for (int i = 1; i <= 10; i++)
    {
        stk.push(i);
    }
    showStack(stk);
    showStackUsingSize(stk);

    stk.pop();
    showStack(stk);

    cout << "Element present at the top of the stack: " << stk.top() << endl;
    cout << "Size of the stack: " << stk.size() << endl;

    return 0;
}