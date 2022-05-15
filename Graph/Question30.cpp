#include <bits/stdc++.h>
using namespace std;

const int NINF = -1e9 - 10;

class Graph
{
public:
    int V, E;
    vector<pair<int, int>> *adj;
    Graph(int v, int e);

    void add_edge(int u, int v, int wt);
    void longestPathDAG(int src);
    void topo_sort(int v, vector<bool> &visited, stack<int> &stk);
};

Graph::Graph(int v, int e)
{
    V = v;
    E = e;
    adj = new vector<pair<int, int>>[V];
}

void Graph::add_edge(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

void Graph::topo_sort(int v, vector<bool> &visited, stack<int> &stk)
{
    visited[v] = true;
    for (auto it : adj[v])
    {
        if (!visited[it.first])
        {
            topo_sort(it.first, visited, stk);
        }
    }

    stk.emplace(v);
}

void Graph::longestPathDAG(int src)
{
    stack<int> stk;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topo_sort(i, visited, stk);

    vector<int> dist(V, NINF);
    dist[src] = 0;

    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();

        if (dist[u] != NINF)
        {
            for (auto it : adj[u])
            {
                if (dist[it.first] < dist[u] + it.second)
                    dist[it.first] = dist[u] + it.second;
            }
        }
    }

    for (auto it : dist)
        it == NINF ? cout << "I " : cout << it << " ";
}

int main()
{
    Graph g(6, 10);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 5, 1);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);

    int s = 1;

    cout << "Disatnces from 1:\n";
    g.longestPathDAG(s);
    return 0;
}