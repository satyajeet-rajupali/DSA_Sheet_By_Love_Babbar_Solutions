#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList, vector<string> &ans)
{
    unordered_set<string> dict;
    int wordSize = beginWord.size();
    int len = 0;
    for (auto it : wordList)
        dict.insert(it);
    queue<string> q;
    q.emplace(beginWord);
    ans.push_back(beginWord);
    string temp;

    if (dict.find(endWord) == dict.end())
        return 0;

    while (!q.empty())
    {
        len++;
        int qlen = q.size();
        for (int i = 0; i < qlen; i++)
        {
            temp = q.front();
            q.pop();

            for (int j = 0; j < wordSize; j++)
            {
                char c = temp[j];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp[j] = ch;
                    if (temp == endWord)
                    {
                        ans.push_back(temp);
                        return len + 1;
                    }
                    if (dict.find(temp) == dict.end())
                        continue;
                    ans.push_back(temp);
                    dict.erase(temp);
                    q.push(temp);
                }
                temp[j] = c;
            }
        }
    }
    return 0;
}

int main()
{
    vector<string> dict = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> ans;
    int lst = ladderLength(beginWord, endWord, dict, ans);
    cout << "Length of Shortest Transformation Sequence: " << lst << "\n";

    if (lst != 0)
    {
        cout << "Shortest Sequence:\n";
        for (auto it : ans)
            cout << it << "-->";
    }

    return 0;
}