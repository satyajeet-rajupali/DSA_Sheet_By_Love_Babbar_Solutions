#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string s)
{
    int open = 0, close = 0;
    int maxlen = 0;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(')
            open++;
        else
            close++;

        if (open == close)
        {
            maxlen = max(maxlen, 2 * close);
        }

        if (close > open)
        {
            open = close = 0;
        }
    }

    open = close = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {

        if (s[i] == '(')
            open++;
        else
            close++;

        if (open == close)
        {
            maxlen = max(maxlen, 2 * open);
        }

        if (open > close)
        {
            open = close = 0;
        }
    }

    return maxlen;
}

int main()
{
    string str = "))()(()";
    cout << "Length of longest valid string: " << findMaxLen(str) << ".\n";

    return 0;
}