#include <bits/stdc++.h>
using namespace std;

bool isPar(string x)
{
    map<char, char> mp;
    mp['}'] = '{';
    mp[')'] = '(';
    mp[']'] = '[';

    int i = 0;
    stack<char> stk;

    while (x[i] != '\0')
    {
        if (x[i] == '{' or x[i] == '(' or x[i] == '[')
        {
            stk.emplace(x[i]);
        }
        else if (x[i] == '}' or x[i] == ')' or x[i] == ']')
        {
            char c = mp[x[i]];
            if (!stk.empty())
            {
                if (stk.top() == c)
                    stk.pop();
                else
                    return false;
            }
            else
                return false;
        }
        i++;
    }

    if (!stk.empty())
        return false;
    return true;
}

int main()
{
    string x = "[(])";
    if (isPar(x))
        cout << "Balanced\n";
    else
        cout << "Imbalanced";

    return 0;
}