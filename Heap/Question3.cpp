#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.emplace(arr[i]);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    sort(ans.begin(), ans.end(), greater<int>());

    return ans;
}

int main()
{
    int v[] = {12, 5, 787, 1, 23};
    int n = sizeof(v) / sizeof(v[0]);
    int k = 2;

    vector<int> ans = kLargest(v, n, k);

    cout << "Ans:\n";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}