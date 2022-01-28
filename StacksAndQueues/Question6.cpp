#include <bits/stdc++.h>
using namespace std;

char *reverse(char *S, int len)
{
    // code here
    stack<char> stk;
    int i = 0;

    while (S[i] != '\0')
    {
        stk.push(S[i]);
        i++;
    }
    i = 0;

    while (!stk.empty())
    {
        S[i] = stk.top();
        i++;
        stk.pop();
    }

    return S;
}

int main()
{
    char str[] = "GeeksforGeeks";
    cout << "Reversed String: " << reverse(str, strlen(str)) << "\n";
    return 0;
}