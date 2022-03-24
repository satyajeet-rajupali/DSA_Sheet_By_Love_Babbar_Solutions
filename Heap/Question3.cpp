#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    vector<int> ans;

    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
            minh.pop();
    }

    for (int i = 0; i < k; i++)
    {
        ans.push_back(minh.top());
        minh.pop();
    }

    sort(ans.begin(), ans.end(), greater<int>());

    return ans;
}

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    int n = 7;
    vector<int> ans = kLargest(arr, n, k);

    if (ans.empty())
        cout << "Nothing received";
    else
    {
        cout << "Ans:\n";
        for (auto it = ans.begin(); it != ans.end(); it++)
            cout << *it << " ";
        cout << "\n";
    }

    return 0;
}