#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

class Graph
{
public:
    int V, E;
    vector<pair<int, int>> *madj;
    vector<int> *adj;
    Graph() {}
    Graph(int v, int e);

    // For Undirected graph
    void add_medge(int u, int v, int wt);

    // For Directed graph
    void add_edge(int u, int v);
    void modifyGraph();

    void shortestPath(int source, int destination);
};

Graph::Graph(int v, int e)
{
    V = v;
    E = e;
    madj = new vector<pair<int, int>>[V];
    adj = new vector<int>[V];
}

void Graph::add_medge(int u, int v, int wt)
{
    madj[u].push_back(make_pair(v, wt));
}

void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::modifyGraph()
{
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            madj[i].push_back(make_pair(it, 0));
            madj[it].push_back(make_pair(i, 1));
        }
    }
}

void Graph::shortestPath(int source, int destination)
{
    // pq<pair<node, distance>>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V, INT_MAX);

    modifyGraph();

    distTo[source] = 0;
    pq.emplace(make_pair(source, 0));

    for (int i = 0; i < V; i++)
    {
        int prev = pq.top().first;
        pq.pop();

        for (auto it : madj[prev])
        {
            int next = it.first;
            int nextdist = it.second;

            if (distTo[next] > distTo[prev] + nextdist)
            {
                distTo[next] = distTo[prev] + nextdist;
                pq.emplace(make_pair(next, distTo[next]));
            }
        }
    }

    if (distTo[destination] == INF)
        cout << -1 << "\n";
    else
        cout << distTo[destination] << "\n";
}

int main()
{
    Graph g(7, 7);
    g.add_edge(0, 1);
    g.add_edge(2, 1);
    g.add_edge(2, 3);
    g.add_edge(6, 3);
    g.add_edge(6, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 1);

    g.shortestPath(0, 6);

    return 0;
}