#include <bits/stdc++.h>
using namespace std;

int kthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> maxH;

    for (int i = 0; i < n; i++)
    {
        maxH.push(arr[i]);
        if (maxH.size() > k)
            maxH.pop();
    }

    return maxH.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "Kth Smallest element: " << kthSmallestElement(arr, n, k) << "\n";

    return 0;
}