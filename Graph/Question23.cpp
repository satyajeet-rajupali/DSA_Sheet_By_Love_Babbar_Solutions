#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v, int s)
{
    cout << "Path:\n";
    cout << s;
    for (auto it : v)
        cout << "-->" << it;
    cout << "-->" << s;
    cout << "\n";
}

void TSP(vector<vector<int>> &graph, int s)
{
    int V = graph.size();
    vector<int> vertex;

    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;

    unordered_map<int, vector<int>> paths;

    do
    {
        int cur_min_path = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            cur_min_path += graph[k][vertex[i]];
            k = vertex[i];
        }

        cur_min_path += graph[k][s];
        paths[cur_min_path] = vertex;
        min_path = min(cur_min_path, min_path);

    } while (next_permutation(vertex.begin(), vertex.end()));
    cout << "Cost: " << min_path << "\n";

    cout << "Shortest Path:\n";
    print(paths[min_path], s);
}

void tspBacktrackingUstil(vector<vector<int>> &graph,
                          vector<bool> &visited,
                          int cur_pos, int n,
                          int count, int cost,
                          int src, int &ans)
{
    if (count == n and graph[cur_pos][src])
    {
        ans = min(ans, cost + graph[cur_pos][src]);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and graph[cur_pos][i])
        {
            visited[i] = true;
            tspBacktrackingUstil(graph, visited, i, n, count + 1, cost + graph[cur_pos][i], src, ans);
            visited[i] = false;
        }
    }
}
void tspBacktracking(vector<vector<int>> graph, int s)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    visited[s] = true;
    int ans = INT_MAX;

    tspBacktrackingUstil(graph, visited, s, n, 1, 0, s, ans);
    cout << "Cost: " << ans << "\n";
}

bool isSafe(int v, int count, vector<int> &path, vector<vector<int>> graph)
{
    // Checks whether a path exist between current and previous node
    if (graph[path[count - 1]][v] == 0)
        return false;

    // Checks whether the vertex has been included or not
    for (int i = 0; i < path.size(); i++)
        if (path[count] == v)
            return false;

    return true;
}

bool hamCycleUtil(int count, int n, vector<int> &path, vector<vector<int>> &graph)
{
    if (count == n)
    {
        if (graph[path[count - 1]][0])
            return true;
        else
            return false;
    }

    for (int i = 1; i < n; i++)
    {

        if (isSafe(i, count, path, graph))
        {
            path[count] = i;
            if (hamCycleUtil(count + 1, n, path, graph))
                return true;
            path[i] = -1;
        }
    }

    return false;
}
void hamcycle(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> path(n, -1);

    path[0] = 0;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    TSP(graph, 0);
    tspBacktracking(graph, 0);

    return 0;
}