#include <bits/stdc++.h>
using namespace std;

int LCS(string A, string B)
{

    int m = A.length();
    int n = B.length();
    int dp[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            if (j == 0)
                dp[i][j] = i;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int res1 = dp[i][j - 1] + 1;
                int res2 = dp[i - 1][j] + 1;
                int res3 = dp[i - 1][j - 1] + 1;
                dp[i][j] = min(res2, min(res1, res3));
            }
        }
    }

    return dp[m][n];
}

int editDistance(string s, string t)
{
    return LCS(s, t);
}

int main()
{
    string s = "ecfbefdcfca";
    string t = "badfcbebbf";
    cout << "Number of Operations: " << editDistance(s, t) << "\n";
    return 0;
}