#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V, E;
    Graph(int V, int E);
    void addEdges(int u, int v, vector<int> adj[]);
    void addEdgesDirectedGraph(int u, int v, vector<int> adj[]);
    void printGraph(vector<int> adj[]);

    // using bfs
    bool isCycle1(int V, vector<int> adj[]);
    bool isCycleUtil1(int cn, vector<int> adj[], vector<bool> &visited);

    // using dfs
    bool isCycle(int V, vector<int> adj[]);
    bool isCycleUtil(int cn, int pn, vector<int> adj[], vector<bool> &visited);
};

// using BFS
bool Graph::isCycleUtil1(int cn, vector<int> adj[], vector<bool> &visited)
{
    queue<pair<int, int>> q;
    visited[cn] = true;
    int pn;
    q.emplace(make_pair(cn, -1));

    while (!q.empty())
    {
        cn = q.front().first;
        pn = q.front().second;

        for (auto j : adj[cn])
        {
            if (!visited[cn])
            {
                visited[cn] = true;
                q.emplace(make_pair(j, cn));
            }
            else if (pn != j)
                return true;
        }
    }
    return false;
}

bool Graph::isCycle1(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (isCycleUtil1(i, adj, visited))
                return true;
        }
    }

    return false;
}

// using DFS
bool Graph::isCycleUtil(int cn, int pn, vector<int> adj[], vector<bool> &visited)
{
    visited[cn] = true;

    for (auto j : adj[cn])
    {
        if (!visited[j])
        {
            if (isCycleUtil(j, cn, adj, visited))
                return true;
            else if (j != pn)
                return true;
        }
    }

    return false;
}
bool Graph::isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (isCycleUtil(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

Graph::Graph(int V, int E)
{
    this->V = V;
    this->E = E;
}

void Graph::printGraph(vector<int> adj[])
{
    cout << "Elements in Graph:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "-->";
        for (int j = 0; j < adj[i].size() - 1; j++)
            cout << adj[i][j] << "-->";
        cout << adj[i][adj[i].size() - 1] << "\n";
    }
}

void Graph::addEdges(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::addEdgesDirectedGraph(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}

int main()
{
    int V, E;
    V = 8;
    E = 9;
    Graph g(V, E);
    vector<int> adj[V];

    g.addEdges(0, 1, adj);
    g.addEdges(1, 2, adj);
    g.addEdges(1, 4, adj);
    g.addEdges(2, 3, adj);
    g.addEdges(3, 4, adj);

    // g.printGraph(adj);

    if (g.isCycle1(V, adj))
        cout << "Cycle Exists!\n";
    else
        cout << "Cycle Doesn't Exists!\n";

    return 0;
}