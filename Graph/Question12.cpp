#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<int> &d)
{
    cout << "Node \t Distance from node\n";
    for (int i = 0; i < d.size(); i++)
        cout << i << "\t\t" << d[i] << "\n";
}

void dijkstra(int V, vector<vector<int>> adj[], int S)
{

    vector<int> d(V, INT_MAX);
    queue<int> q;
    q.emplace(S);
    d[S] = 0;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        for (auto i : adj[t])
        {
            int nn = i[0];
            int wt = i[1];
            if (d[nn] > d[t] + wt)
            {
                d[nn] = d[t] + wt;
                q.emplace(nn);
            }
        }
    }

    printSolution(d);
}

int main()
{
    int V = 3;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});

    adj[1].push_back({0, 1});
    adj[1].push_back({2, 3});

    adj[2].push_back({0, 6});
    adj[2].push_back({1, 3});

    dijkstra(3, adj, 2);

    return 0;
}