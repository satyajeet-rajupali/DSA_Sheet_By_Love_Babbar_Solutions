#include <bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    // Your code here
    int i = 0;
    stack<char> stk;
    map<char, char> mp;
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';

    

    while (x[i] != '\0')
    {
        if (x[i] == '{' or x[i] == '[' or x[i] == '(')
        {
            stk.emplace(x[i]);
        }
        else if (x[i] == '}' or x[i] == ']' or x[i] == ')')
        {
            char c = mp[x[i]];

            if (!stk.empty())
            {
                if (stk.top() == c)
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        i++;
    }

    if (stk.empty())
    {
        return true;
    }

    return false;
}

int main()
{
    string str = "))((";
    if (ispar(str))
    {
        cout << "Paranthesis is Balanced\n";
    }
    else
    {
        cout << "Paranthesis isn't Balanced\n";
    }
    return 0;
}