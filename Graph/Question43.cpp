#include <bits/stdc++.h>
using namespace std;

bool twoCliqueOrNotUtil1(int source, vector<vector<int>> &graph, int n, vector<int> &color)
{
    queue<int> q;

    color[source] = 0;

    q.emplace(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int k = 0; k < n; k++)
        {
            if (graph[u][k] and color[k] != -1)
            {
                color[k] = 1 - color[u];
                q.emplace(k);
            }
            else if (graph[u][k] and color[k] == color[u])
                return false;
        }
    }

    return true;
}

bool twoCliqueOrNotUtil(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] != -1)
            if (!twoCliqueOrNotUtil1(i, graph, n, color))
                return false;
    }

    return true;
}

bool twoCliqueOrNot(int source, vector<vector<int>> &graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = (i != j) ? !graph[i][j] : 0;
        }
    }
    return twoCliqueOrNotUtil(graph);
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 1, 0},
                                 {1, 0, 1, 0, 0},
                                 {1, 1, 0, 0, 0},
                                 {0, 1, 0, 0, 1},
                                 {0, 0, 0, 1, 0}};

    twoCliqueOrNot(0, graph) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}