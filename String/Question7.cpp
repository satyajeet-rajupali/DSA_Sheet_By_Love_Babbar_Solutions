#include <bits/stdc++.h>
using namespace std;

string longestPalin(string S)
{
    int low, high;
    int start = 0, end = 1;
    int lenOfString = S.length();
    string ans = "";
    for (int i = 1; i < lenOfString; i++)
    {
        cout << "For i: " << i << "\n";
        // Even Case
        low = i - 1;
        high = i;
        cout << "Even Case:\n";
        while (low >= 0 and high < lenOfString and S[low] == S[high])
        {
            if (((high - low) + 1) > end)
            {
                start = low;
                end = (high - low) + 1;
                cout << "Start: " << start << " "
                     << "End: " << end << "\n";
            }
            low--;
            high++;
        }

        // Odd Case
        low = i - 1;
        high = i + 1;
        cout << "Odd Case:\n";
        while (low >= 0 and high < lenOfString and S[low] == S[high])
        {
            if (((high - low) + 1) > end)
            {
                start = low;
                end = (high - low) + 1;
                cout << "Start: " << start << " "
                     << "End: " << end << "\n";
            }
            low--;
            high++;
        }
    }
    cout << "Start: " << start << " "
         << "End: " << end << "\n";
    ans = S.substr(start, end);
    cout << "Ans: " << ans << "\n";
    return ans;
}

int main()
{
    string s = "aaaabbaa";
    cout << "Longest Palindrome: " << longestPalin(s) << "\n";
    return 0;
}