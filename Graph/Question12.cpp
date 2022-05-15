#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<int> &d)
{
    cout << "Node \t Distance from node\n";
    for (int i = 0; i < d.size(); i++)
        cout << i << "\t\t" << d[i] << "\n";
}

void dijkstraUsingPriorityQueue(int V, int source, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V, INT_MAX);

    distTo[source] = 0;
    pq.emplace(make_pair(0, source));

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        // vector<pair<int, int>>::iterator it;
        for (auto it : adj[prev])
        {
            int next = it.first;
            int nextDist = it.second;

            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.emplace(make_pair(distTo[next], next));
            }
        }
    }

    cout << "Distance from " << source << " is:\n";
    for (int i = 0; i < V; i++)
        cout << i << "--" << distTo[i] << "\n";
    cout << "\n";
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
    cout << "\n";

    vector<pair<int, int>> adj1[V];
    adj1[0].push_back({1, 1});
    adj1[0].push_back({2, 6});

    adj1[1].push_back({0, 1});
    adj1[1].push_back({2, 3});

    adj1[2].push_back({0, 6});
    adj1[2].push_back({1, 3});

    dijkstraUsingPriorityQueue(3, 2, adj1);

    return 0;
}