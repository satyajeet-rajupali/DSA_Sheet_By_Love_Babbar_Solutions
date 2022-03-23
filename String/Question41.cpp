#include <bits/stdc++.h>
using namespace std;

// Using Maps
bool areIsomorphic(string str1, string str2)
{
    if (str1.size() == 0 or str2.size() == 0 or str1.size() != str2.size())
        return false;

    map<char, char> store;
    for (int i = 0; str1[i]; i++)
    {
        if (store.find(str1[i]) == store.end())
            store[str1[i]] = str2[i];
        else
        {
            if (store[str1[i]] != str2[i])
                return false;
        }
    }

    return true;
}

bool areIsomorphic1(string str1, string str2)
{
    if (str1.size() != str2.size())
        return false;

    int mp1[26], mp2[26];

    memset(mp1, -1, sizeof(mp1));
    memset(mp2, -1, sizeof(mp2));

    for (int i = 0; str1[i]; i++)
    {
        char ch1 = str1[i];
        char ch2 = str2[i];

        if (mp1[ch1 - 'a'] != -1 && mp1[ch1 - 'a'] != ch2)
            return false;

        if (mp2[ch2 - 'a'] != -1 && mp2[ch2 - 'a'] != ch1)
            return false;

        mp1[ch1 - 'a'] = ch2;
        mp2[ch2 - 'a'] = ch1;
    }

    return true;
}

int main()
{
    string str1 = "aab", str2 = "xxz";
    if (areIsomorphic1(str1, str2))
        cout << "Isomorphic"
             << "\n";
    else
        cout << "Not Isomorphic\n";
    return 0;
}