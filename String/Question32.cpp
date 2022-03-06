#include <bits/stdc++.h>
using namespace std;

string findSubString(string str)
{
    int count(0), n = str.length(), i(0), j(1);
    set<char> st;
    unordered_map<char, int> mp;
    for (int i1 = 0; i1 < n; i1++)
        st.insert(str[i1]);
    n = st.size();
    mp[str[i]]++;
    count++;
    int mi = INT_MAX;
    while (i <= j and j < str.length())
    {
        // Expansion of Windows
        if (count < n)
        {
            if (mp[str[j]] == 0)
                count++;
            mp[str[j]]++;
            j++;
        }
        else if (count == n)
        {
            mi = min(mi, j - i);
            if (mp[str[i]] == 1)
                count--;
            mp[str[i]]--;
            i++;
        }
    }

    while (count == n)
    {
        mi = min(mi, j - i);
        if (mp[str[i]] == 1)
            count--;
        mp[str[i]]--;
        i++;
    }
    cout << "i: " << i << " j: " << j << "\n";
    return str.substr(i - 1, mi);
}

int main()
{
    string s = "CCABBAbBCABB";
    cout << "Smallest Distinct Window: " << findSubString(s) << "\n";

    return 0;
}