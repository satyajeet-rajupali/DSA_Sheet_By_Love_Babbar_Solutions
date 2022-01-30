#include <bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
    // Your code here
    stack<int> stk;
    long long maxArea = 0;
    int i = 0;

    while (i < n)
    {
        if (stk.empty() or arr[stk.top()] <= arr[i])
            stk.push(i++);
        else
        {
            int tp = stk.top();
            stk.pop();
            long long ans = arr[tp] * (stk.empty() ? i : i - stk.top() - 1);
            maxArea = max(maxArea, ans);
        }
    }

    while (!stk.empty())
    {
        int tp = stk.top();
        stk.pop();
        long long ans = arr[tp] * (stk.empty() ? i : i - stk.top() - 1);
        maxArea = max(maxArea, ans);
    }

    return maxArea;
}

int main()
{
    long long arr[] = {6, 2, 5, 4, 5, 1, 6};

    cout << "Max Area: " << getMaxArea(arr, sizeof(arr) / sizeof(arr[0])) << "\n";

    return 0;
}