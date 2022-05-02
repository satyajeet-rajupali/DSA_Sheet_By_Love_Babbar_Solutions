#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V, E;
    Graph(int V, int E);
    void addEdges(int u, int v, vector<int> adj[]);
    void addEdgesDirectedGraph(int u, int v, vector<int> adj[]);
    bool isCyclic(int V, vector<int> adj[]);
    bool isCyclicUtil(int pos, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsVisited);
    void printGraph(vector<int> adj[]);
};

bool Graph::isCyclicUtil(int pos, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsVisited)
{
    visited[pos] = true;
    dfsVisited[pos] = true;

    for (auto j : adj[pos])
    {
        if (visited[j] == false)
        {
            if (isCyclicUtil(j, adj, visited, dfsVisited))
                return true;
        }
        else if (dfsVisited[j])
            return true;
    }
    dfsVisited[pos] = false;
    return false;
}

// Using BFS to check whether a cycle exists or not
bool Graph::isCyclic(int V, vector<int> adj[])
{
    vector<bool> dfsVisited(V, false);
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (isCyclicUtil(i, adj, visited, dfsVisited))
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
    // cout << "Enter V and E:\n";
    // cin >> V >> E;
    V = 11;
    E = 11;
    Graph g(V, E);
    vector<int> adj[V];

    g.addEdgesDirectedGraph(7, 0, adj);
    g.addEdgesDirectedGraph(0, 4, adj);
    g.addEdgesDirectedGraph(4, 5, adj);
    g.addEdgesDirectedGraph(5, 6, adj);
    g.addEdgesDirectedGraph(6, 8, adj);
    g.addEdgesDirectedGraph(8, 9, adj);
    g.addEdgesDirectedGraph(9, 3, adj);
    g.addEdgesDirectedGraph(3, 2, adj);
    g.addEdgesDirectedGraph(2, 1, adj);
    g.addEdgesDirectedGraph(1, 10, adj);
    g.addEdgesDirectedGraph(4, 6, adj);

    // g.printGraph(adj);

    // cout << "BFS Traversal:\n";
    if (g.isCyclic(V, adj))
        cout << "Cycle Exists!\n";
    else
        cout << "Cycle Doesn't Exists!\n";

    return 0;
}