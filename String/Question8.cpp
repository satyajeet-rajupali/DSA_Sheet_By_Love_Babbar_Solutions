#include <bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str)
{
    int n = str.length();
    int dp[n + 1][n + 1] = {0};

    cout << "\n\nBefore adding anything in dp:\n";
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << "i:" << i << " j:" << j << "\n";
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
                cout << "when i or j is zero:->  i:" << i << " j:" << j << "\n";
            }
            else if (str[i - 1] == str[j - 1] and i != j)
            {
                cout << "Comparing " << str[i - 1] << " and " << str[j - 1] << "\n";
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cout << "when i or j not equal and char is same:->  i:" << i << " j:" << j << " dp: " << dp[i][j] << "\n";
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                cout << "else case:->  i:" << i << " j:" << j << " dp: " << dp[i][j] << "\n";
            }
        }
    }

    cout << "\n\nAfter adding ans in dp:\n";
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return dp[n][n];
}

int main()
{
    string str = "axxxy";
    cout << "Longest Repeating Subsequence: " << LongestRepeatingSubsequence(str) << "\n";
    return 0;
}