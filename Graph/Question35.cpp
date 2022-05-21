#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V, E;
    vector<pair<int, int>> *adj;
    Graph() {}
    Graph(int v, int e);

    // For Undirected graph
    void add_edge(int u, int v, int wt);

    // For Directed graph
    void add_edged(int u, int v, int wt);

    bool solve(int src, int k, vector<bool> &visited);
    bool solve1(int src, int k, int cw, vector<bool> &visited);
};

Graph::Graph(int v, int e)
{
    V = v;
    E = e;
    adj = new vector<pair<int, int>>[V];
}

// For Undirected graph
void Graph::add_edge(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// For Directed graph
void Graph::add_edged(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

bool Graph::solve(int src, int k, vector<bool> &visited)
{
    if (k <= 0)
        return true;

    for (auto it : adj[src])
    {
        int v = it.first;
        int wt = it.second;

        if (visited[v])
            continue;

        if (wt >= k)
            return true;

        visited[v] = true;
        if (solve(v, k - wt, visited))
            return true;

        visited[v] = false;
    }

    return false;
}

bool Graph::solve1(int src, int k, int cw, vector<bool> &visited)
{
    if (cw >= k)
        return true;

    for (auto it : adj[src])
    {

        int v = it.first;
        int wt = it.second;

        if (cw >= k)
            return true;

        if (visited[v])
            continue;

        if (cw + wt >= k)
            return true;

        visited[v] = true;

        if (solve1(src, k, cw + wt, visited))
            return true;

        visited[v] = false;
    }

    return false;
}

int main()
{
    Graph g(9, 14);

    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);

    vector<bool> visited(10, false);
    visited[0] = true;
    g.solve(0, 61, visited) ? cout << "Yes\n" : cout << "No\n";

    vector<bool> visited1(10, false);
    visited1[0] = true;
    g.solve1(0, 61, 0, visited1) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}