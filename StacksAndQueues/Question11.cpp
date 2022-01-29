#include <bits/stdc++.h>
using namespace std;


int isOperand(char x)
{

    if (x == '-' or x == '+' or x == '*' or x == '/')
        return 0;
    return 1;
}

int evaluation(char *postfix)
{

    stack<int> stk;
    int i, x1, x2, r;

    for (int i = 0; postfix[i] != '\0'; i++)
    {

        if (isOperand(postfix[i]))
        {
            stk.emplace(postfix[i] - '0');
        }
        else
        {

            x2 = stk.top();
            stk.pop();

            x1 = stk.top();
            stk.pop();

            switch (postfix[i])
            {
            case '*':
                r = x1 * x2;
                stk.push(r);
                break;

            case '/':
                r = x1 / x2;
                stk.push(r);
                break;

            case '+':
                r = x1 + x2;
                stk.push(r);
                break;

            case '-':
                r = x1 - x2;
                stk.push(r);
                break;

            default:
                break;
            }
        }
    }
    r = stk.top();
    stk.pop();
    return r;
}

int main()
{
    char postfix[] = "08/";
    cout << "Answer: " << evaluation(postfix) << "\n";

    return 0;
}

