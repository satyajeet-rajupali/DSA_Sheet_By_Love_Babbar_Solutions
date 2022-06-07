#include <bits/stdc++.h>
using namespace std;

int kthSmallestElement(int v[], int n, int k)
{
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.emplace(v[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    return maxHeap.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << "Kth smallest Element: " << kthSmallestElement(arr, n, k) << "\n";

    return 0;
}