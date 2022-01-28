#include <bits/stdc++.h>
using namespace std;

class KStacks
{

private:
    int free, *top, *arr, *next, k, n;

public:
    KStacks(int k, int n);
    bool isEmpty(int stackNum);
    bool isFull();

    void push(int value, int stackNum);
    int pop(int stackNum);

    void display();
};

KStacks::KStacks(int k, int n)
{
    this->k = k;
    this->n = n;
    free = 0;
    top = new int[this->k];
    arr = new int[this->n];
    next = new int[this->n];

    for (int i = 0; i < k; i++)
        top[i] = -1;

    for (int i = 0; i < this->n - 1; i++)
        next[i] = i + 1;
    next[this->n - 1] = -1;
}

bool KStacks::isFull()
{
    return (free == -1);
}

bool KStacks::isEmpty(int stackNum)
{
    return (top[stackNum] == -1);
}

void KStacks::push(int value, int stackNum)
{
    if (isFull())
    {
        cout << "Stack Overflow\n";
        return;
    }

    int i = free;
    free = next[i];

    next[i] = top[stackNum];

    top[stackNum] = i;

    arr[i] = value;
}

void KStacks::display()
{

    for (int i = 0; i < k; i++)
    {
        cout << "Stack-" << i + 1 << ":\n";
        for (int j = top[i];; j = next[j])
        {
            if (next[j] != -1)
                cout << arr[j] << " ";
            else
            {
                cout << arr[j] << " ";
                break;
            }
        }
        cout << "\n";
    }
}

int KStacks::pop(int stackNum)
{

    int data = -1;
    if (isEmpty(stackNum))
    {
        cout << "Stack Underflow\n";
        return data;
    }

    int i = top[stackNum];
    top[stackNum] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}

int main()
{

    KStacks ks = KStacks(3, 10);

    // Pushing elements in stack-1, stack-2, stack-3
    ks.push(10, 2);
    ks.push(15, 2);
    ks.push(17, 1);

    ks.push(49, 1);
    ks.push(45, 2);
    ks.push(11, 0);

    ks.push(39, 1);
    ks.push(9, 0);
    ks.push(7, 0);

    ks.display();

    cout << "Element Popped from stack-1: " << ks.pop(0) << "\n";
    cout << "Element Popped from stack-2: " << ks.pop(1) << "\n";
    cout << "Element Popped from stack-2: " << ks.pop(2) << "\n";

    ks.display();

    return 0;
}
