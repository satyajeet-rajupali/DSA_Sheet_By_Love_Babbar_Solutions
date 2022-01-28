#include <bits/stdc++.h>
using namespace std;

class Stack
{

private:
    int top1, top2, size;
    int *stack;

public:
    Stack(int size);
    void push1(int data);
    void push2(int data);

    int pop1();
    int pop2();

    void display();
};

Stack::Stack(int size)
{
    this->size = size;
    stack = new int[this->size];
    for (int i = 0; i < size; i++)
        stack[i] = -1;
    top1 = -1;
    top2 = size;
}

void Stack::push1(int data)
{
    if (top2 - top1 - 1 != 0)
    {
        top1++;
        stack[top1] = data;
    }
    else
    {
        cout << "Stack Overflow\n";
    }
}

void Stack::push2(int data)
{
    if (top2 - top1 - 1 != 0)
    {
        top2--;
        stack[top2] = data;
    }
    else
    {
        cout << "Stack Overflow\n";
    }
}

int Stack::pop1()
{

    if (top1 == -1)
    {
        return -1;
    }
    else
    {
        int p = stack[top1];
        stack[top1] = -1;
        top1--;
        return p;
    }
}

int Stack::pop2()
{

    if (top2 == size)
    {
        return -1;
    }
    else
    {
        int p = stack[top2];
        stack[top2] = -1;
        top2++;
        return p;
    }
}

void Stack::display()
{

    cout << "Elements in the stack:\n";
    for (int i = 0; i < size; i++)
        cout << stack[i] << " ";

    cout << "\n";
}

int main()
{

    Stack stk = Stack(6);

    stk.push1(1);
    // stk.push1(2);
    // stk.push1(3);

    // stk.push2(6);
    // stk.push2(5);
    stk.push2(4);

    stk.pop1();
    stk.pop1();
    stk.pop2();
    stk.pop2();

    stk.display();
    return 0;
}