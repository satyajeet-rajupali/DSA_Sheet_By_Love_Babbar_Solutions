#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V, E;
    vector<int> *adj;
    Graph() {}
    Graph(int v, int e);

    // For Undirected graph
    void add_edge(int u, int v);

    // For Directed graph
    void add_edged(int u, int v);

    int journeyToMoon(int n, vector<vector<int>> astronaut);
    void DFS(int v, int &count, vector<bool> &visited, vector<int> a[]);
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

void Graph::DFS(int v, int &count, vector<bool> &visited, vector<int> a[])
{
    visited[v] = true;
    count++;
    for (auto it : a[v])
        if (!visited[it])
            DFS(it, count, visited, a);
}

int Graph::journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<int> a[n];

    for (auto it : astronaut)
    {
        a[it[0]].push_back(it[1]);
        a[it[1]].push_back(it[0]);
    }

    vector<int> sol;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int count = 0;
            DFS(i, count, visited, a);
            sol.push_back(count);
            cout << "\n";
        }
    }

    int val = (n * (n - 1)) / 2;
    for (auto it : sol)
    {
        int x = (it * (it - 1)) / 2;
        val -= x;
    }
    return val;
}

int main()
{
    vector<vector<int>> v = {{0, 2}};
    int n = 4;
    Graph g;
    int val = g.journeyToMoon(n, v);
    cout << "Pairs Count: " << val << "\n";
    return 0;
}