#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V, E;
    vector<int> *adj;

    Graph(int vertex, int edges);

    void addEdges(int u, int v);
    void BFSutil();
    void DFSutil();
    void BFS(int u, vector<bool> &visited);
    void DFS(int u, vector<bool> &visited);
    void topologicalSortingUsingBFS(); //  Kahn's Algorithm
};

void Graph::topologicalSortingUsingBFS() //  Kahn's Algorithm
{
    queue<int> q;
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.emplace(i);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (auto it : adj[x])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.emplace(it);
        }
    }

    return;
}

Graph::Graph(int vertex, int edges)
{
    V = vertex;
    E = edges;
    adj = new vector<int>[V];
}

void Graph::addEdges(int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void Graph::BFS(int u, vector<bool> &visited)
{
    queue<int> q;

    visited[u] = true;
    q.emplace(u);

    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();

        for (int y : adj[x])
        {
            if (!visited[y])
            {
                visited[y] = true;
                q.emplace(y);
            }
        }
    }
}

void Graph::BFSutil()
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            BFS(i, visited);
        }
    }
}

void Graph::DFSutil()
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(i, visited);
        }
    }
}

void Graph::DFS(int u, vector<bool> &visited)
{
    if (visited[u])
        return;

    visited[u] = true;
    cout << u << " ";

    for (int x : adj[u])
    {
        if (!visited[x])
        {
            DFS(x, visited);
        }
    }
}

int main()
{
    Graph g(6, 6);
    g.addEdges(5, 2);
    g.addEdges(5, 0);
    g.addEdges(4, 0);
    g.addEdges(4, 1);
    g.addEdges(2, 3);
    g.addEdges(3, 1);

    cout << "BFS Traversal:\n";
    g.BFSutil();
    cout << "\n";

    cout << "DFS Traversal:\n";
    g.DFSutil();
    cout << "\n";

    cout << "Toplogical Sorting\n";
    g.topologicalSortingUsingBFS();
    cout << "\n";

    return 0;
}