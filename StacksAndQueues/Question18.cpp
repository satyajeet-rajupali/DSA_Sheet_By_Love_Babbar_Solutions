#include <bits/stdc++.h>
using namespace std;

// With Stack
// TC: O(N), SC:(N)
bool checkRedundancy(string str)
{

    stack<int> stk;
    bool ans = false;

    for (int i = 0; str[i] != '\0'; i++)
    {

        if (str[i] == '+' or str[i] == '-' or str[i] == '*' or str[i] == '/')
        {
            stk.emplace(str[i]);
        }
        else if (str[i] == '(')
        {
            stk.emplace(str[i]);
        }
        else if (str[i] == ')')
        {
            if (stk.top() == '(')
                return true;

            while (stk.top() == '+' or stk.top() == '-' or stk.top() == '*' or stk.top() == '/')
            {
                stk.pop();
            }
            stk.pop();
        }
    }
    return ans;
}

// Without Stack
// TC: O(N), SC: O(N)
int checkRedundancy1(string str)
{
    int a = 0, b = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' and str[i + 2] == ')')
            return 1;

        if (str[i] == '+' or str[i] == '-' or str[i] == '*' or str[i] == '/')
            a++;
        else if (str[i] == '(')
            b++;
    }

    if (b > a)
        return 1;
    return 0;
}

int main()
{
    string str = "(a+(b)/c)";

    if (checkRedundancy(str))
    {
        cout << "Redundancy\n";
    }
    else
    {
        cout << "No redundancy\n";
    }


    if (checkRedundancy1(str))
    {
        cout << "Redundancy1\n";
    }
    else
    {
        cout << "No redundancy1\n";
    }

    return 0;
}