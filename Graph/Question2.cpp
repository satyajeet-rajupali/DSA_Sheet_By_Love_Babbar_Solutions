#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, false);
    vector<int> ans;
    queue<int> q;
    int starting_vertex = 0;
    q.emplace(starting_vertex);
    visited[starting_vertex] = true;
    ans.push_back(starting_vertex);
    int u;

    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for (auto i : adj[u])
        {

            if (visited[i] == false)
            {
                ans.push_back(i);
                visited[i] = true;
                q.emplace(i);
            }
        }
    }

    return ans;
}

int main()
{
    int V, E;
    cout << "Enter V and E:\n";
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = bfsOfGraph(V, adj);

    cout << "BFS Traversal:\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}