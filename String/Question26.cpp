#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
        return "";
    if (strs.size() == 1)
        return strs[0];"geeksforgeeks", "geeks",
                           "geek", "geezer"

    sort(strs.begin(), strs.end());
    int i = 0;

    int minSize = min(strs[0].length(), strs[strs.size() - 1].length());

    string first = strs[0];
    string last = strs[strs.size() - 1];

    while (i < minSize and first[i] == last[i])
        i++;

    string ans = first.substr(0, i);

    return ans;
}

int main()
{
    vector<string> strs = {"DEREK", "DEEP", "DECKER"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << "\n";
    return 0;
}