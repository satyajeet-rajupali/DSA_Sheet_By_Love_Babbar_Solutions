#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int isPresentInB(string A, vector<string> &B)
{
    for (int i = 0; i < B.size(); i++)
    {
        if (A.compare(B[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int solve(string A, vector<string> &B)
{

    if (A.size() == 0)
        return 1;
    if (isPresentInB(A, B))
        return 1;
    bool flag = 0;
    if (mp.find(A) != mp.end())
        return mp[A];

    for (int k = 1; k < A.length(); k++)
    {
        int temp = (solve(A.substr(0, k), B) and solve(A.substr(k, A.length() - k), B));
        if (temp == 1)
        {
            flag = 1;
            break;
        }
    }
    return mp[A] = flag;
}

int wordBreak(string A, vector<string> &B)
{
    if (solve(A, B))
        return 1;
    return 0;
}

int main()
{
    vector<string> B = {"i",
                        "like",
                        "sam",
                        "sung",
                        "samsung",
                        "mobile",
                        "ice",
                        "cream",
                        "icecream",
                        "man",
                        "go",
                        "mango"};
    string A = "iicecreamlike";

    if (wordBreak(A, B))
        cout << "Aavilable\n";
    else
        cout << "Unavailable\n";
    return 0;
}