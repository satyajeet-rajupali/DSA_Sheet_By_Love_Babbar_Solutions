#include <iostream>
#include <queue>

using namespace std;

void showPriorityQueue(priority_queue<int> pq)
{
    cout << "Elements in the priority queue(using empty() as a factor):\n";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void showPriorityQueueUsingSize(priority_queue<int> pq)
{
    cout << "Elements in the priority queue(using size() as a factor):\n";
    while (pq.size() > 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void showMinPriorityQueue(priority_queue<int, vector<int>, greater<int>> pq)
{
    cout << "Elements in the Min priority queue(using empty() as a factor):\n";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void showMinPriorityQueueUsingSize(priority_queue<int, vector<int>, greater<int>> pq)
{
    cout << "Elements in the Min priority queue(using size() as a factor):\n";
    while (pq.size() > 0)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> gpq;

    for (int i = 1; i <= 10; i++)
    {
        pq.push(i);
    }

    for (int i = 1; i <= 10; i++)
    {
        gpq.push(i);
    }

    showPriorityQueue(pq);
    showPriorityQueueUsingSize(pq);
    showMinPriorityQueue(gpq);
    showMinPriorityQueueUsingSize(gpq);

    cout<<"Element at the top of the queue pq: "<<pq.top()<<endl;
    cout<<"Element at the top of the queue gpq: "<<gpq.top()<<endl;

    pq.emplace(-1);
    gpq.emplace(-1);
    showMinPriorityQueue(gpq);
    showPriorityQueue(pq);


    return 0;
}