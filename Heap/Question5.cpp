#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> ppi;

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    vector<int> ans;
    priority_queue<ppi, vector<ppi>, greater<ppi>> minHeap;
    for (int i = 0; i < K; i++)
        minHeap.emplace(make_pair(arr[i][0], make_pair(i, 0)));

    while (!minHeap.empty())
    {
        ppi cur = minHeap.top();
        minHeap.pop();

        ans.push_back(cur.first);

        int i = cur.second.first;
        int j = cur.second.second;

        if (j + 1 < arr[i].size())
            minHeap.emplace(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
    }

    return ans;
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 3;

    vector<int> ans = mergeKArrays(v, k);
    cout << "Answer:\n";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}