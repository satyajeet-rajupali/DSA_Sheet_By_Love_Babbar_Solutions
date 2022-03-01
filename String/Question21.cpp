#include <bits/stdc++.h>
using namespace std;

long long int dp[1001][1001];
long long int M = 10e9 + 7;

long long int countPS(int i, int j, string str)
{
    if (i > j)
        return 0;

    if (i == j)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str[i] == str[j])
    {
        long long int one, two;
        if (dp[i + 1][j] != -1 && i< str.length()-1)
            one = dp[i + 1][j];
        else
            one = countPS(i + 1, j, str)%M;

        if (dp[i][j - 1] != -1 && j>0)
            two = dp[i][j - 1];
        else
            two = countPS(i, j - 1, str)%M;

        return dp[i][j] = (1 + one + two) % M;
    }
    else
    {
        long long int one, two, three;
        if (dp[i + 1][j] != -1 and i< str.length()-1)
            one = dp[i + 1][j];
        else
            one = countPS(i + 1, j, str)%M;

        if (dp[i][j - 1] != -1 and j>0)
            two = dp[i][j - 1];
        else
            two = countPS(i, j - 1, str)%M;

         if (dp[i+1][j - 1] != -1 and i< str.length()-1 and j>0)
            three = dp[i+1][j - 1];
        else
            three = countPS(i+1, j - 1, str)%M;


        return dp[i][j] = (one + two - three) % M;
    }
}

long long int countPS(string str)
{
    return countPS(0, str.length() - 1, str) % M;
}

int main()
{
    string s = "abca";
    memset(dp, -1, sizeof(dp));
    cout << "Count: " << countPS(s) << "\n";
    return 0;
}