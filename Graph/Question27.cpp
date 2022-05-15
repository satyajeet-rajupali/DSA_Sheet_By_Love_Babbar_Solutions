#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V, E;
    vector<int> *adj;
    vector<int> *tps; // Transpose of adj
    Graph(int v, int e);

    // For Undirected graph
    void add_edge(int u, int v);

    // For Directed graph
    void add_edged(int u, int v);

    // Count the cycle (For directed graph)
    void kosarajuAlgo();
    void dfs(int v, vector<bool> &visited, stack<int> &stk);
    void rev_dfs(int v, vector<bool> &visited);
};

Graph::Graph(int v, int e)
{
    V = v;
    E = e;
    adj = new vector<int>[V];
    tps = new vector<int>[V];
}

// For Undirected graph
void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// For Directed graph
void Graph::add_edged(int u, int v)
{
    adj[u].push_back(v);
}

// Topological Sorting
void Graph::dfs(int v, vector<bool> &vis, stack<int> &stk)
{
    vis[v] = true;
    for (auto it : adj[v])
        if (!vis[it])
            dfs(it, vis, stk);

    stk.emplace(v);
}

void Graph::rev_dfs(int v, vector<bool> &vis)
{
    vis[v] = true;
    cout << v << " ";
    for (auto it : tps[v])
        if (!vis[it])
            rev_dfs(it, vis);
}

void Graph::kosarajuAlgo()
{
    // Step-1: Sort the vertexes according to their finishing time- using toposort.
    stack<int> stk;
    vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i, visited, stk);

    // Step-2: Take transpose of the graph.
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        for (auto it : adj[i])
            tps[it].push_back(i);
    }

    // Step-3 Perform reverse dfs based on the toposort order
    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();

        if (!visited[node])
        {
            count++;
            cout << "SCC:\n";
            rev_dfs(node, visited);
            cout << "\n";
        }
    }

    cout << "SCC Count: " << count << "\n";
}

int main()
{
    Graph g(5, 5);
    g.add_edged(0, 2);
    g.add_edged(2, 1);
    g.add_edged(1, 0);
    g.add_edged(0, 3);
    g.add_edged(3, 4);

    g.kosarajuAlgo();

    return 0;
}