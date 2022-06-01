#include <bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    // Merging both the sorted arrays without using extraa space
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        pq.push(arr2[i]);
    }
    int x;
    for (int i = 0; i < k; i++)
    {
        x = pq.top();
        pq.pop();
    }
    return x;
}

int main()
{

    int arr1[] = {1, 10, 10, 25, 40, 54, 79};
    int arr2[] = {15, 24, 27, 32, 33, 39, 48, 68, 82, 88, 90};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 15;
    cout << "Ans: " << kthElement(arr1, arr2, n, m, k) << "\n";
    return 0;
}