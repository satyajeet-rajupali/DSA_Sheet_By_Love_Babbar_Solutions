#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    if (s.length() == 0 or s.length() == 1)
        return s;

    unordered_map<char, int> um;
    string ans = "";

    // pair<frequency, charachter
    priority_queue<pair<int, char>> maxHeap;

    for (int i = 0; s[i]; i++)
        um[s[i]]++;

    for (auto it = um.begin(); it != um.end(); it++)
        maxHeap.emplace(make_pair(it->second, it->first));

    int lastCharCount = 0;
    char lastChar = '#';

    while (!maxHeap.empty())
    {
        int currCharCount = maxHeap.top().first;
        char currChar = maxHeap.top().second;
        maxHeap.pop();

        ans += currChar;
        currCharCount--;

        if (lastCharCount > 0)
            maxHeap.emplace(make_pair(lastCharCount, lastChar));

        lastChar = currChar;
        lastCharCount = currCharCount;
    }
    
    if (ans.length() != s.length())
        return "";
    else
    {
        return ans;
    }
}

int main()
{
    string s = "aab";
    cout << "Ans: " << reorganizeString(s) << "\n";

    return 0;
}