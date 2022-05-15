#include <bits/stdc++.h>
using namespace std;

class Prims
{
public:
    vector<int> key;
    vector<bool> mst;
    vector<int> parent;

    Prims(int n);
    void addEdges(int u, int v, int wt, vector<pair<int, int>> adj[]);
    void prims(int n, vector<pair<int, int>> adj[]); // Brute Force Approach
    void PrimsOptimized(int n, vector<pair<int, int>> adj[]);
};

Prims::Prims(int n)
{
    key = vector<int>(n + 1, INT_MAX);
    parent = vector<int>(n + 1, -1);
    mst = vector<bool>(n + 1, false);
}

void Prims::addEdges(int u, int v, int wt, vector<pair<int, int>> adj[])
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void Prims::prims(int n, vector<pair<int, int>> adj[])
{
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        int u = -1, mini;
        for (int v = 0; v < n; v++)
            if (!mst[v] and (u == -1 or key[v] < mini))
                mini = key[v], u = v;

        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (!mst[v] and wt < key[v])
                key[v] = wt, parent[v] = u;
        }
    }
    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += key[i];

    cout << "MST Cost: " << cost << "\n";
    cout << "Edges of MST obtained:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << "--" << i << "\n";
}

void Prims::PrimsOptimized(int n, vector<pair<int, int>> adj[])
{
    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(make_pair(0, 0));

    for (int i = 0; i < n - 1; i++)
    {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;

            if (!mst[v] and wt < key[v])
            {
                key[v] = wt;
                pq.emplace(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += key[i];

    cout << "MST Cost: " << cost << "\n";
    cout << "Edges of MST obtained:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << "--" << i << "\n";
}

int main()
{
    int n = 5;
    Prims k(n);
    vector<pair<int, int>> adj[n];
    k.addEdges(0, 1, 2, adj);
    k.addEdges(0, 3, 6, adj);
    k.addEdges(3, 1, 8, adj);
    k.addEdges(1, 2, 3, adj);
    k.addEdges(1, 4, 5, adj);
    k.addEdges(2, 4, 7, adj);

    Prims k1(n);
    vector<pair<int, int>> adj1[n];
    k1.addEdges(0, 1, 2, adj1);
    k1.addEdges(0, 3, 6, adj1);
    k1.addEdges(3, 1, 8, adj1);
    k1.addEdges(1, 2, 3, adj1);
    k1.addEdges(1, 4, 5, adj1);
    k1.addEdges(2, 4, 7, adj1);

    cout << "Brute Force:\n";
    k.prims(n, adj);
    cout << "\n";
    cout << "Efficient Approach:\n";
    k1.PrimsOptimized(n, adj1);

    return 0;
}