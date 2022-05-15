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

    // Checks if a given graph is bipartite or not
    bool isBipartite();

    // Checks if a given graph is bipartite or not using BFS Algorithm
    bool isBipartiteUsingBFSUtil();
    bool isBipartiteUsingBFS(int src, vector<int> &color);

    // Checks if a given graph is bipartite or not using DFS Algorithm
    bool isBipartiteUsingDFSUtil();
    bool isBipartiteUsingDFS(int v, vector<int> &color);
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

bool Graph::isBipartite()
{
    vector<int> color(V, -1);
    vector<bool> available(V, false);

    color[0] = 0;

    for (int i = 1; i < V; i++)
    {
        for (auto it : adj[i])
            if (color[it] != -1)
                available[color[it]] = true;

        int j = 0;
        for (j = 0; j < V; j++)
            if (!available[j])
                break;

        color[i] = j;

        for (auto it : adj[i])
            if (color[it] != -1)
                available[color[it]] = false;
    }

    for (int i = 0; i < V; i++)
        if (color[i] > 1)
            return false;

    return true;
}

bool Graph::isBipartiteUsingBFS(int src, vector<int> &color)
{
    queue<int> q;

    color[src] = 0;
    q.emplace(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.emplace(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }

    return true;
}

bool Graph::isBipartiteUsingBFSUtil()
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartiteUsingBFS(i, color))
                return false;
        }
    }
    return true;
}

bool Graph::isBipartiteUsingDFS(int v, vector<int> &color)
{

    if (color[v] == -1)
        color[v] = 0;

    for (auto it : adj[v])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[v];
            if (!isBipartiteUsingDFS(it, color))
                return false;
        }
        else if (color[it] == color[v])
            return false;
    }
    return true;
}

bool Graph::isBipartiteUsingDFSUtil()
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
            if (!isBipartiteUsingDFS(i, color))
                return false;
    }
    return true;
}

int main()
{
    Graph g(5, 10);

    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    // g.add_edge(4, 5);

    g.isBipartiteUsingDFSUtil() ? cout << "Yes\n" : cout << "No\n";

    return 0;
}