#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;

public:
    Graph(int v);
    ~Graph() { delete adj; }
    void addEdge(int u, int v);
    void colorGraph();
};

Graph::Graph(int v)
{
    V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::colorGraph()
{
    vector<int> color(V, -1);
    vector<bool> available(V, false);

    color[0] = 0;

    for (int i = 1; i < V; i++)
    {
        for (auto it : adj[i])
            if (color[it] != -1)
                available[color[it]] = true;
        int j;
        for (j = 0; j < V; j++)
            if (!available[j])
                break;

        color[i] = j;

        for (auto it : adj[i])
            if (color[it] != -1)
                available[color[it]] = false;
    }
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << color[u] << endl;
}

int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloring of graph 1 \n";
    g1.colorGraph();

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of graph 2 \n";
    g2.colorGraph();

    return 0;
}