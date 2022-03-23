#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // code here
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < string_list.size(); i++)
    {
        string str = string_list[i];
        sort(str.begin(), str.end());
        m[str].push_back(string_list[i]);
    }

    vector<vector<string>> ans(m.size());
    int index = 0;
    for (auto x : m)
    {
        auto v = x.second;
        for (int i = 0; i < v.size(); i++)
            ans[index].push_back(v[i]);
        index++;
    }

    return ans;
}

int main()
{
    vector<string> words = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> ans = Anagrams(words);

    cout << "Answer:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}