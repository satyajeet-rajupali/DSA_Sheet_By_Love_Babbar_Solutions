#include <bits/stdc++.h>
using namespace std;

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

class BellmanFord
{
public:
    vector<int> dist;
    vector<cell> edges;
    int V, E;

    BellmanFord(int V, int E);
    void addEdges(int u, int v, int wt);
    void BellmanFordAlgorithm();
};

BellmanFord::BellmanFord(int V, int E)
{
    this->V = V;
    this->E = E;
    dist = vector<int>(V, 10000000);

    // edges = vector<cell>(E);
}

void BellmanFord::addEdges(int u, int v, int wt)
{
    edges.push_back(cell(u, v, wt));
}

void BellmanFord::BellmanFordAlgorithm()
{
    dist[0] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        cout << "i: " << i << "\n";
        for (auto it : edges)
            if (dist[it.u] + it.wt < dist[it.v])
                dist[it.v] = dist[it.u] + it.wt;
    }

    int check = 0;

    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "Negative weight Cycle Detected\n";
            check = 1;
            return;
        }
    }

    if (!check)
    {
        cout << "Nodes \t Distances\n";
        for (int i = 0; i < V; i++)
            cout << i << "\t" << dist[i] << "\n";
    }
}

int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    // Code here

    vector<int> dist(n, 10000000);

    dist[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    int flag = 0;

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] + wt < dist[v])
        {
            flag = 1;
            return flag;
        }
    }

    return flag;
}

int main()
{
    int V = 6;
    int E = 7;
    BellmanFord b(V, E);
    b.addEdges(3, 2, 6);
    b.addEdges(5, 3, 1);
    b.addEdges(0, 1, 5);
    b.addEdges(1, 5, -3);
    b.addEdges(1, 2, -2);
    b.addEdges(3, 4, -2);
    b.addEdges(2, 4, 3);

    b.BellmanFordAlgorithm();

    return 0;
}