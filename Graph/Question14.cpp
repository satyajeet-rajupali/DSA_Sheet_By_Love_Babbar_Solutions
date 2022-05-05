#include <bits/stdc++.h>
using namespace std;

void printJobTime(vector<int> &job)
{
    cout << "Time Taken:\n";
    for (auto it : job)
        cout << it << " ";
    cout << "\n";
}

void addEdge(int u, int v, vector<int> adj[], vector<int> &indegree)
{
    adj[u].push_back(v);
    indegree[v]++;
}

void calculateTime(int V, vector<int> adj[], vector<int> &indegree)
{
    vector<int> job(V, 0);
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.emplace(i);
            job[i] = 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto it : adj[cur])
        {
            indegree[it]--;

            if (indegree[it] == 0)
            {
                job[it] = job[cur] + 1;
                q.emplace(it);
            }
        }
    }

    printJobTime(job);
}

int main()
{
    int V = 10;

    vector<int> adj[V];
    vector<int> indegree(V, 0);

    // Given Directed Edges of graph
    addEdge(1, 3, adj, indegree);
    addEdge(1, 4, adj, indegree);
    addEdge(1, 5, adj, indegree);
    addEdge(2, 3, adj, indegree);
    addEdge(2, 8, adj, indegree);
    addEdge(2, 9, adj, indegree);
    addEdge(3, 6, adj, indegree);
    addEdge(4, 6, adj, indegree);
    addEdge(4, 8, adj, indegree);
    addEdge(5, 8, adj, indegree);
    addEdge(6, 7, adj, indegree);
    addEdge(7, 8, adj, indegree);
    addEdge(8, 10, adj, indegree);

    calculateTime(10, adj, indegree);

    return 0;
}