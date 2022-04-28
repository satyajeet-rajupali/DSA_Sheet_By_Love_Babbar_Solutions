#include <bits/stdc++.h>
using namespace std;

void DFS(int pos, vector<int> adj[], vector<bool> &visited)
{
    if (visited[pos] == false)
    {
        cout << pos << " ";
        visited[pos] = true;

        for (auto i : adj[pos])
        {
            if (visited[i] == false)
                DFS(i, adj, visited);
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter V and E:\n";
    cin >> V >> E;

    vector<int> adj[V+1];

    for (int i = 1; i < E+1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V+1, false);

    cout << "DFS Traversal:\n";
    DFS(1, adj, visited);

    return 0;
}