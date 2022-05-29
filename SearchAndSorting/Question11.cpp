#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int FindMaxUtil(int arr[], int i)
{
    if (i <= -1)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int op1 = FindMaxUtil(arr, i - 2) + arr[i];
    int op2 = FindMaxUtil(arr, i - 1);

    return dp[i] = max(op1, op2);
}

// DP-Question
int FindMaxSum(int arr[], int n)
{
    
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = arr[0];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

int main()
{
    int v[] = {1, 2, 3};
    int N = sizeof(v) / sizeof(v[0]);
    // cout << "Max Element: " << v[peakElement(v, N, 0, N - 1)] << "\n";
    int mx = FindMaxSum(v, N);
    cout << "Max Sum: " << mx << "\n";
    return 0;
}