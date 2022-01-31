#include <bits/stdc++.h>
using namespace std;

bool checkStackPermutation(int in[], int op[], int n)
{

    queue<int> iq;
    for (int i = 0; i < n; i++)
        iq.push(in[i]);

    queue<int> oq;
    for (int i = 0; i < n; i++)
        oq.push(op[i]);

    stack<int> inputStack;
    while (!iq.empty())
    {
        int val = iq.front();
        iq.pop();

        if (val == oq.front())
        {
            oq.pop();
            while (!inputStack.empty())
            {
                if (inputStack.top() == oq.front())
                {
                    inputStack.pop();
                    oq.pop();
                }
                else
                    break;
            }
        }
        else
            inputStack.emplace(val);
    }

    if (inputStack.empty() && iq.empty())
        return true;
    return false;
}

int main()
{
    int input[] = {1, 2, 3};
    int output[] = {3, 1, 2};

    if (checkStackPermutation(input, output, sizeof(input) / sizeof(input[0])))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}