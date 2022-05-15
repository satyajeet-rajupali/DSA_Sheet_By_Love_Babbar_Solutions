#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

struct cell
{
    int u;
    int v;
    int wt;
    cell() {}
    cell(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph
{
public:
    int V, E;
    vector<cell> adj;
    vector<int> dist;
    Graph(int v, int e);

    // For Undirected graph
    void add_edge(int u, int v, int wt);

    // For Directed graph
    void add_edged(int u, int v, int wt);

    // Using Bellmanford algorithm (It will work for connected graphs)
    bool checkNegativeCycle();

    // For disconnected graph (Extensions of Bellmanford algorithm)
    bool checkNegativeCycleUtil();
    bool checkNegativeCycle(int src);

    // Using Flloyd Warshall, this will work for both connected as well
    // disconnected graphs.
    bool flloydWarshall(vector<vector<int>> &graph, int n);
};

Graph::Graph(int v, int e)
{
    V = v;
    E = e;
    dist = vector<int>(V, 10000007);
}

// For Undirected graph
void Graph::add_edge(int u, int v, int wt)
{
    adj.push_back(cell(u, v, wt));
}

bool Graph::checkNegativeCycle()
{
    dist[0] = 0;

    for (int i = 0; i < V - 1; i++)
    {

        for (auto it : adj)
        {
            if (dist[it.u] + it.wt < dist[it.v])
                dist[it.v] = dist[it.u] + it.wt;
        }
    }

    bool check = false;

    for (auto it : adj)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            check = true;
        }
    }

    return check;
}

bool Graph::checkNegativeCycle(int src)
{
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {

        for (auto it : adj)
        {
            if (dist[it.u] + it.wt < dist[it.v])
                dist[it.v] = dist[it.u] + it.wt;
        }
    }

    bool check = false;

    for (auto it : adj)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            check = true;
        }
    }

    return check;
}

bool Graph::checkNegativeCycleUtil()
{

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (checkNegativeCycle(i))
                return true;

            for (int i = 0; i < V; i++)
            {
                if (dist[i] != 10000007)
                {
                    visited[i] = true;
                }
            }
        }
    }

    return false;
}

bool Graph::flloydWarshall(vector<vector<int>> &graph, int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // if (graph[i][j] != INF and graph[k][j] != INF) to be used in case of Negative Weights
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (graph[i][i] < 0)
            return true;

    return false;
}

int main()
{
    Graph g(5, 8);

    g.add_edge(0, 1, -1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 2);
    g.add_edge(1, 4, 2);
    g.add_edge(3, 2, 5);
    g.add_edge(3, 1, 1);
    g.add_edge(4, 3, -3);

    // g.checkNegativeCycleUtil() ? cout << "Negative cycle exists\n" : cout << "Negative cycle doesn't exists\n";

    vector<vector<int>> graph = {{0, INF, INF, INF, INF},
                                 {INF, 0, 1, INF, INF},
                                 {INF, INF, 0, -1, INF},
                                 {INF, INF, INF, 0, -1},
                                 {INF, -1, INF, INF, 0}};

    g.flloydWarshall(graph, 4) ? cout << "Negative cycle exists\n" : cout << "Negative cycle doesn't exists\n";

    return 0;
}