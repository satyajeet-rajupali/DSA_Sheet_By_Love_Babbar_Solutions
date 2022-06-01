#include <bits/stdc++.h>
using namespace std;

void printVector(vector<long long int> v)
{

    cout << "Elements:\n";
    for (auto it : v)
        cout << it << " ";
    cout << "\n";
}

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    // code here
    vector<long long int> ans(n);
    vector<long long int> pre(n);
    vector<long long int> pos(n);

    pre[0] = 1;
    pos[n - 1] = 1;

    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] * nums[i - 1];

    for (int i = n - 2; i >= 0; i--)
        pos[i] = pos[i + 1] * nums[i + 1];

    for (int i = 0; i < n; i++)
        ans[i] = pre[i] * pos[i];

    return ans;
}

int main()
{
    vector<long long int> v = {0, 12};
    printVector(productExceptSelf(v, v.size()));
    return 0;
}