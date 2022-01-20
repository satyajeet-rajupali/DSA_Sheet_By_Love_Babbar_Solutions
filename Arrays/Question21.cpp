#include <bits/stdc++.h>
using namespace std;

void factorial(int num)
{

    vector<int> ans = {1};

    for (int i = 1; i <= num; i++)
    {

        int carry = 0;
        for (auto it = ans.begin(); it != ans.end(); it++)
        {
            int prod = (*it) * i + carry;
            *it = prod % 10;
            carry = prod / 10;
        }

        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    cout << "Answer:\n";
    reverse(ans.begin(), ans.end());
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it;
    cout << "\n";
}

int main()
{
    factorial(1000);
    return 0;
}