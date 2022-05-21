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
    bool graphColoring(bool graph[101][101], int m, int n);
    bool solve(int node, vector<int> color, int m, int n, bool graph[101][101]);
    bool check(int node, vector<int> color, int n, int col, bool graph[101][101]);
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

bool Graph::check(int node, vector<int> color, int n, int col, bool graph[101][101])
{
    for (int k = 0; k < n; k++)
        if (k != node and graph[k][node] and color[k] == col)
            return false;
    return true;
}

bool Graph::solve(int node, vector<int> color, int m, int n, bool graph[101][101])
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (check(node, color, n, i, graph))
        {
            color[node] = i;
            if (solve(node + 1, color, m, n, graph))
                return true;
            color[node] = 0;
        }
    }

    return false;
}

bool Graph::graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> colors(n, 0);

    if (solve(0, colors, m, n, graph))
        return true;

    return false;
}

int main()
{
    int m = 1;
    int n = 5;

    bool graph[101][101] = {{false, false, false, false, true},
                            {false, false, false, false, false},
                            {false, false, false, false, true},
                            {false, false, false, false, true},
                            {true, false, true, true, false}};
    // {{false, true, true, true},
    //                         {true, false, true, false},
    //                         {true, true, false, true},
    //                         {true, false, true, false}};
    Graph g;
    g.graphColoring(graph, m, n) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}