#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<int> adj[])
{
    // Code here
    vector<vector<int>> ans(V);
    for (int i = 0; i < V; i++)
    {
        ans[i].push_back(i);
        for (auto j : adj[i])
            ans[i].push_back(j);
    }
    return ans;
}

int main()
{
    int V, E;
    cout << "Enter vertices and edges:\n";
    cin >> V >> E;
    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cout << "Enter u and v:\n";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans = printGraph(V, adj);
    cout << "Size of ans: " << ans.size() << "\n";

    cout << "Elements in adjacency list:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size() - 1; j++)
            cout << ans[i][j] << "-->";
        cout << ans[i][ans[i].size() - 1] << "\n";
    }

    return 0;
}