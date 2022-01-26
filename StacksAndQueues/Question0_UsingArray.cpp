#include <bits/stdc++.h>
using namespace std;

class Stack
{

private:
    int top = -1, n;
    int *stack;

public:
    Stack(int arr[], int size, int sizeOfStack);
    void push(int data);
    bool isFull();
    bool isEmpty();
    int pop();
    int peek(int index);
    int stack_top();
    void display();
};

Stack::Stack(int arr[], int size, int sizeOfStack)
{
    stack = new int[sizeOfStack];
    n = sizeOfStack;

    for (int i = 0; i < sizeOfStack; i++)
    {

        if (i < size)
        {
            top++;
            stack[top] = arr[i];
        }
        else
        {
            stack[i] = -1;
        }
    }
}

bool Stack::isEmpty()
{

    if (top == -1)
        return true;
    return false;
}

bool Stack::isFull()
{
    if (top == n - 1)
        return true;
    return false;
}

void Stack::push(int data)
{
    if (isFull())
    {
        cout << "Stack OverFlow"
             << "\n";
        return;
    }
    top++;
    stack[top] = data;
}

int Stack::pop()
{

    int dat = -1;

    if (isEmpty())
    {
        cout << "Stack UnderFlow\n";
        return dat;
    }
    else
    {
        dat = stack[top];
        top--;
        return dat;
    }
}

int Stack::peek(int index)
{

    int data = -1;
    if (index > top || index < 0)
    {
        cout << "\nInvalid Index\n";
        return data;
    }
    else
    {
        return stack[top - index + 1];
    }
}

int Stack::stack_top()
{

    if (isEmpty())
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    else
    {
        return stack[top];
    }
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Elements in the stack:\n";
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << "\n";
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    Stack stk = Stack(arr, sizeof(arr) / sizeof(arr[0]), 7);
    stk.display();

    stk.push(6);
    stk.display();

    stk.pop();
    stk.pop();
    stk.display();

    cout << "Element at top: " << stk.stack_top() << "\n";
    cout << "Element at 3: " << stk.peek(5) << "\n";
}