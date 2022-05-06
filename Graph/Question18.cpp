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

class DisjointSet
{
public:
    vector<int> rank;
    vector<int> parent;
    vector<cell> edges;

    void addEdges(int u, int v, int wt);
    DisjointSet(int n);
    int findPar(int node);
    void Union(int u, int v);

    void kruskalsAlgorithm();
};

DisjointSet::DisjointSet(int n)
{
    rank = vector<int>(n + 1, 0);
    parent = vector<int>(n + 1, 0);

    for (int i = 0; i < n + 1; i++)
        parent[i] = i;
}

bool comp(cell a, cell b)
{
    return a.wt < b.wt;
}

int DisjointSet::findPar(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findPar(parent[node]);
}

void DisjointSet::Union(int u, int v)
{
    int pu = findPar(u);
    int pv = findPar(v);

    if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

void DisjointSet::addEdges(int u, int v, int wt)
{
    edges.push_back(cell(u, v, wt));
}

void DisjointSet::kruskalsAlgorithm()
{
    sort(edges.begin(), edges.end(), comp);

    vector<pair<int, int>> mst;
    int cost = 0;
    for (auto it : edges)
    {
        if (findPar(it.u) != findPar(it.v))
        {
            mst.push_back({it.u, it.v});
            cost += it.wt;
            Union(it.u, it.v);
        }
    }

    cout << "Total Cost: " << cost << "\n";
    cout << "Edges:\n";
    for (auto it : mst)
        cout << it.first << "--" << it.second << "\n";
}

int main()
{
    DisjointSet dj(7);
    dj.addEdges(1, 5, 4);
    dj.addEdges(5, 4, 9);
    dj.addEdges(1, 4, 1);
    dj.addEdges(1, 2, 2);
    dj.addEdges(4, 2, 3);
    dj.addEdges(4, 3, 5);
    dj.addEdges(3, 6, 8);
    dj.addEdges(3, 2, 3);
    dj.addEdges(2, 6, 7);

    dj.kruskalsAlgorithm();

    return 0;
}