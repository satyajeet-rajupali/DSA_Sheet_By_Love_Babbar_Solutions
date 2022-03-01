#include <bits/stdc++.h>
using namespace std;

// KMP algorithm
vector<int> prefix_function(string s)
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

    return pi;
}

int KMP(string pattern, string text)
{

    vector<int> prefixTable = prefix_function(pattern);
    int pos = -1;
    int i(0), j(0);

    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = prefixTable[j - 1];
            }
            else
            {
                i++;
            }
        }

        if (j == pattern.size())
        {
            pos = i - pattern.size();
            break;
        }
    }

    return pos;
}

int lps(string s)
{
    // Your code goes here
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

int main()
{
    string pattern = "ababd";

    string text = "ababcabcabaabababd";

    cout << "Pattern found at: " << KMP(pattern, text) << "\n";
    cout << "Longest Prefix length: " << lps(pattern) << "\n";

    return 0;
}