#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2)
{
    // your code here
    int m = s1.length(), n = s2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i < n + 1; i++)
        dp[0][i] = 0;
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";
    cout << "LCS: " << lcs(str1.length(), str2.length(), str1, str2) << "\n";
    return 0;
}