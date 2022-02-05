#include <bits/stdc++.h>
using namespace std;

void display(vector<int> v)
{

    cout << "Elements in vector:\n";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

vector<int> nextSmaller(vector<int> v, int n)
{

    stack<int> stk;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        while (!stk.empty() && v[i] <= stk.top())
            stk.pop();

        ans[i] = stk.empty() ? -1 : stk.top();
        stk.push(v[i]);
    }
    return ans;
}

int main()
{
    vector<int> v = {4, 8, 5, 2, 25};

    vector<int> ans = nextSmaller(v, v.size());

    cout << "Answer:\n";
    display(ans);

    return 0;
}