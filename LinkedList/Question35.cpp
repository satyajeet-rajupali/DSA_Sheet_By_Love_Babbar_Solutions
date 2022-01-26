#include <bits/stdc++.h>
using namespace std;

// aabc
// a#bb

string FirstNonRepeating(string A)
{
    string ans = "";
    vector<int> entries(26, 0); // This is to maintain the frquency of chars in A.
    vector<char> order;         //  This is to preserve the order of chars in A.

    for (int i = 0; i < A.length(); i++)
    {

        if (!entries[A[i] - 'a'])
        {
            order.push_back(A[i]);
        }

        entries[A[i] - 'a']++;

        // This is to make sure that if stream doesn't contain any non-repeating chars then
        // it will make sure that '#' gets entered in the ans.
        int f = 0;
        for (int j = 0; j < order.size(); j++)
        {

            if (entries[order[j] - 'a'] == 1)
            {
                f = 1;
                ans.push_back(order[j]);
                break;
            }
        }

        if (f == 0)
        {
            ans.push_back('#');
        }
    }

    return ans;
}

int main()
{
    string c = "zz";
    cout << "Answer: " << FirstNonRepeating(c) << "\n";
    return 0;
}