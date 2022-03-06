#include <bits/stdc++.h>
using namespace std;

int minimumNumberOfSwaps(string S)
{
    // code here
    int balanced(0), ans(0), n = S.length();
    for (int i = 0; i < n; i++)
    {

        if (S[i] == '[')
            balanced++;
        else
        {
            balanced--;
            if (balanced < 0)
                ans += abs(balanced);
        }
    }

    return balanced + ans;
}

int main()
{
    string s = "[]][][";
    cout << "Min Swaps: " << minimumNumberOfSwaps(s) << "\n";
    return 0;
}