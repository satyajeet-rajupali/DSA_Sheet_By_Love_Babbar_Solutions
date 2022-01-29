#include <bits/stdc++.h>
using namespace std;

// arr[] = [1 3 2 4]

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> stk;
    vector<long long> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[i] >= stk.top())
        {
            stk.pop();
        }

        ans[i] = stk.empty() ? -1 : stk.top();
        stk.emplace(arr[i]);
    }

    return ans;
}

int main()
{
    vector<long long> vec = {6, 8, 0, 1, 3};

    vector<long long> ans = nextLargerElement(vec, vec.size());

    cout << "Answer:\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}