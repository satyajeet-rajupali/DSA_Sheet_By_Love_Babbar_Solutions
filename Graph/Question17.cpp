#include <bits/stdc++.h>
using namespace std;

void topologicalSort(int v, string &res, vector<int> adj[], vector<bool> &visited)
{
    visited[v] = true;
    for (auto it : adj[v])
        if (!visited[it])
            topologicalSort(it, res, adj, visited);
    char ch = v + 'a';
    res.push_back(ch);
}

void createGraph(vector<int> adj[], string dict[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        for (int j = 0; j < min(s1.size(), s2.size()); j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
}

string findOrder(string dict[], int N, int K)
{
    // code here
    vector<int> adj[K];
    vector<bool> visited(K, false);
    createGraph(adj, dict, N);
    string ans = "";
    for (int i = 0; i < K; i++)
    {
        if (!visited[i])
            topologicalSort(i, ans, adj, visited);
    }

    return ans;
}

int main()
{
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    int N = 5;
    int K = 4;
    string ans = findOrder(dict, N, K);
    cout << "Order: " << ans << "\n";

    return 0;
}