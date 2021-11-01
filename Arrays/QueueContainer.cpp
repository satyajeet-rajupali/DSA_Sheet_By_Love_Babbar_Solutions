#include <iostream>
#include <queue>

using namespace std;

void showQueueUsingSize(queue<int> q)
{
    cout << "Elemenets in queue(using size() as factor):\n";
    while (q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void showQueue(queue<int> q)
{
    cout << "Elemenets in queue(using empty() as factor):\n";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q1;

    for (int i = 1; i <= 10; i++)
    {
        q1.emplace(i);
    }

    showQueue(q1);
    showQueueUsingSize(q1);

    cout << "Element at front of the queue: " << q1.front() << endl;
    cout << "Element at back of the queue: " << q1.back() << endl;

    q1.push(11);
    showQueue(q1);
    q1.pop();
    showQueue(q1);

    cout << "Size of Queue: " << q1.size();
    return 0;
}