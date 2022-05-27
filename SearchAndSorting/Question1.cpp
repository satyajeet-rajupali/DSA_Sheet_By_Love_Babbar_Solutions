#include <bits/stdc++.h>
using namespace std;

vector<int> valueEqualToIndex(int arr[], int n)
{
    // code here
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i+1)
            ans.push_back(arr[i]);
    }
    return ans;
}

int main()
{
    int arr[] = {1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = valueEqualToIndex(arr, n);

    cout << "Ans:\n";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}