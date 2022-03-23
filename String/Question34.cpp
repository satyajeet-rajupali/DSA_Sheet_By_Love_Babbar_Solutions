#include <bits/stdc++.h>
using namespace std;

int lps(string s)
{
    int n = s.length();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi[n - 1];
}

int minCharsRequired(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    string concat = str + '$' + revStr;

    return str.length() - lps(concat);
}

// Dynamic Programming Approach
int lcs(string str1, string str2, int s1, int s2)
{
    int dp[s1 + 1][s2 + 1];

    for (int i = 0; i < s1 + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < s2 + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < s1 + 1; i++)
    {
        for (int j = 1; j < s2 + 1; j++)
        {
            if (str2[j] == str1[i])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[s1][s2];
}

int minCharsRequired1(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());

    int n = rev.length();
    return n - lcs(str, rev, n, n);
}

int main()
{
    string str = "AACECAAAA";
    // int ans = minCharsRequired(str);
    // cout << "Ans: " << ans << "\n";
    string revstr = str;
    reverse(revstr.begin(), revstr.end());
    cout << "Ans: " << minCharsRequired1(str) << "\n";

    return 0;
}