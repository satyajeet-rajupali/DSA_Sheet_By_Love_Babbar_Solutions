#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(unordered_map<int, vector<int>> &adj,
             int node,
             vector<bool> &visited)
    {
        if (!visited[node])
        {
            visited[node] = true;

            for (auto x : adj[node])
            {
                if (!visited[x])
                    DFS(adj, x, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {

        unordered_map<int, vector<int>> m;
        int edges = 0;
        int components = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < connections.size(); i++)
        {
            m[connections[i][0]].push_back(connections[i][1]);
            m[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                components += 1;
                DFS(m, i, visited);
            }
        }

        if (edges < n - 1)
            return -1;

        int redundants = edges - ((n - 1) - (components - 1));

        if (redundants >= (components - 1))
            return components - 1;
        return -1;
    }
};

int main()
{

    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    Solution s;
    cout << "Min Connections: " << s.makeConnected(6, connections) << "\n";
    return 0;
}