#include <bits/stdc++.h>
using namespace std;

void printElements(vector<int> vertices)
{
    cout << "Sorted Vertices:\n";
    for (auto it : vertices)
        cout << it << " ";
    cout << "\n";
}
void topoSortUtil(int v, vector<int> adj[], vector<bool> &visited, stack<int> &stk)
{
    if (!visited[v])
    {
        visited[v] = true;

        for (auto it : adj[v])
        {
            if (!visited[it])
                topoSortUtil(it, adj, visited, stk);
        }

        stk.emplace(v);
    }
}

// Using DFS and Stack
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    stack<int> stk;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topoSortUtil(i, adj, visited, stk);
        }
    }

    while (!stk.empty())
    {
        /* code */
        ans.push_back(stk.top());
        stk.pop();
    }

    printElements(ans);

    return ans;
}

// Using BFS(Kahn's Algorithm)
vector<int> topoSort1(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> ans;
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.emplace(i);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for (auto it : adj[temp])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.emplace(it);
        }
    }

    printElements(ans);

    return ans;
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    adj[2].push_back(3);

    adj[3].push_back(1);

    adj[4].push_back(0);
    adj[4].push_back(1);

    adj[5].push_back(0);
    adj[5].push_back(2);

    topoSort1(V, adj);
    return 0;
}