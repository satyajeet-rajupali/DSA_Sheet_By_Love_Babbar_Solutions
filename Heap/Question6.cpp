#include <bits/stdc++.h>
using namespace std;

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here
    vector<int> ans;
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
        maxHeap.emplace(a[i]);

    for (int i = 0; i < m; i++)
        maxHeap.emplace(b[i]);

    while (!maxHeap.empty())
    {
        ans.push_back(maxHeap.top());
        maxHeap.pop();
    }

    return ans;
}

int main()
{
    vector<int> a = {10, 5, 6, 2};
    int n = a.size();
    vector<int> b = {12, 7, 9};
    int m = b.size();

    vector<int> c = mergeHeaps(a, b, n, m);

    cout << "Ans:\n";
    for (auto it : c)
        cout << it << " ";
    cout << "\n";

    return 0;
}