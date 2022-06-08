#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
    for (auto it : v)
        cout << it << " ";
    cout << "\n";
}

int kthLargestSumContiguousSubArray(vector<int> v, int n, int k)
{

    vector<int> temp;
    int t = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(v[i]);
        t = v[i];
        for (int j = i + 1; j < n; j++)
        {
            t += v[j];
            temp.push_back(t);
        }
    }
    print(temp);

    for (int i = 0; i < temp.size(); i++)
    {
        minHeap.emplace(temp[i]);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    return minHeap.top();
}

int main()
{
    vector<int> v = {10, -10, 20, -40};
    int k = 6;

    int ans = kthLargestSumContiguousSubArray(v, v.size(), k);
    cout << "kthLargestSum: " << ans << "\n";

    return 0;
}