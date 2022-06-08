#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    // Your code here
    long long cost = 0;

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (long long i = 0; i < n; i++)
        minHeap.emplace(arr[i]);

    while (minHeap.size() >= 2)
    {
        long long first = minHeap.top();
        minHeap.pop();

        long long second = minHeap.top();
        minHeap.pop();

        long long t = first + second;
        cost += (t);
        minHeap.emplace(t);
    }
    return cost;
}

int main()
{
    long long arr[] = {4, 3, 2, 6};
    long long n = 4;
    cout << "Ans: " << minCost(arr, n) << "\n";
    return 0;
}