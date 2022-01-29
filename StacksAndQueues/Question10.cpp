#include <bits/stdc++.h>
using namespace std;

int isOperand(char x)
{

    if (x == '-' or x == '+' or x == '*' or x == '/')
        return 0;
    return 1;
}

int pre(char x)
{

    if (x == '-' or x == '+')
        return 1;
    else if (x == '*' or x == '/')
        return 2;
    return 0;
}

char *convertInfixToPostfix(char *infix)
{

    stack<char> stk;
    int i = 0, j = 0;
    char *postfix = new char[strlen(infix) + 1];

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {

            if (stk.empty())
            {
                stk.emplace(infix[i++]);
            }
            else if (pre(infix[i]) > pre(stk.top()))
            {
                stk.emplace(infix[i++]);
            }
            else
            {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }

    while (!stk.empty())
    {
        postfix[j++] = stk.top();
        stk.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

// Expression with parenthesis
int isOperand1(char x)
{

    if (x == '+' or x == '-' or x == '*' or x == '/' or x == '^' or x == '(' or x == ')')
        return 0;
    return 1;
}

int inStackPrecedence(char x)
{

    if (x == '+' or x == '-')
        return 2;
    else if (x == '*' or x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    return -1;
}

int outStackPrecedence(char x)
{

    if (x == '+' or x == '-')
        return 1;
    else if (x == '*' or x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    return -1;
}

char *convertInfixToPostfix1(char *infix)
{

    stack<char> stk;
    int i = 0, j = 0;
    char *postifix = new char[strlen(infix) + 1];

    while (infix[i] != '\0')
    {
        if (isOperand1(infix[i]))
            postifix[j++] = infix[i++];
        else
        {

            if (stk.empty() || outStackPrecedence(infix[i]) > inStackPrecedence(stk.top()))
                stk.emplace(infix[i++]);
            else if (outStackPrecedence(infix[i]) == inStackPrecedence(stk.top()))
                stk.pop();
            else
            {
                postifix[j++] = stk.top();
                stk.pop();
            }
        }
    }

    while (!stk.empty() and stk.top() != ')')
    {
        postifix[j++] = stk.top();
        stk.pop();
    }
    postifix[j] = '\0';
    return postifix;
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
                cout<<"r: "<<r<<"\n";
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
    char infix[] = "((a+b)*c)-d^e^f";

    // cout << "Postfix: " << convertInfixToPostfix(infix) << "\n";
    // cout << "Postfix: " << convertInfixToPostfix1(infix) << "\n";

    char postfix[] = "08/";
    cout << "Answer: " << evaluation(postfix) << "\n";

    return 0;
}