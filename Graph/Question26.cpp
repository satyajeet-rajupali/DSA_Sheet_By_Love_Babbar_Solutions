#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V, E;
    vector<int> *adj;
    Graph(int v, int e);

    // For Undirected graph
    void add_edge(int u, int v);

    // For Directed graph
    void add_edged(int u, int v);

    // To check for the bridges in graph
    void dfs(int v, int parent, int &timer,
             vector<int> &tin,
             vector<int> &low,
             vector<bool> &visited);
    void dfs_util();
};

Graph::Graph(int v, int e)
{
    V = v;
    E = e;
    adj = new vector<int>[V];
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

void Graph::dfs(int v, int parent, int &timer,
                vector<int> &tin,
                vector<int> &low,
                vector<bool> &visited)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;

    for (auto it : adj[v])
    {
        if (it == parent)
            continue;

        if (!visited[it])
        {
            dfs(it, v, timer, tin, low, visited);
            low[v] = min(low[it], low[v]);
            if (low[it] > tin[v])
                cout << v << "--" << it << "\n";
        }
        else
            low[v] = min(low[v], tin[it]);
    }
}

void Graph::dfs_util()
{
    vector<int> tin(V, -1);
    vector<int> low(V, -1);
    vector<bool> visited(V, false);

    int timer = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, timer, tin, low, visited);
        }
    }
}

int main()
{
    // Graph g(5, 10);
    // g.add_edge(0, 1);
    // g.add_edge(0, 2);
    // g.add_edge(0, 3);
    // g.add_edge(1, 2);
    // g.add_edge(3, 4);

    Graph g(4, 6);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);

    cout << "Bridges in the graph:\n";
    g.dfs_util();

    return 0;
}