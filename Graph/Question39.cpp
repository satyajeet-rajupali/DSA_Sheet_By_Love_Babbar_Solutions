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
    void printCoverVertexes();
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

void Graph::printCoverVertexes()
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {

            for (auto it : adj[i])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    cout << "Vertex Cover:\n";
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
            cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    Graph g(5, 4);
    g.add_edge(0, 2);
    g.add_edge(2, 4);
    g.add_edge(1, 4);
    g.add_edge(3, 4);

    g.printCoverVertexes();

    return 0;
}