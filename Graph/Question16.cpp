#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j,
            vector<vector<bool>> &visited,
            vector<vector<char>> &graph)
{
    int r = graph.size();
    int c = graph[0].size();
    return (i >= 0 and i < r) and
           (j >= 0 and j < c) and
           (!visited[i][j] and graph[i][j] == '1');
}

// Using BFS
void numIslandsUsingBFS(int si, int sj,
                        vector<vector<bool>> &visited,
                        vector<vector<char>> &grid)
{
    // Code here
    vector<int> dx = {0, 0, -1, 1, -1, -1, 1, 1};
    vector<int> dy = {-1, 1, 0, 0, -1, 1, -1, 1};

    queue<pair<int, int>> q;
    q.emplace(make_pair(si, sj));
    visited[si][sj] = true;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            if (isSafe(i + dx[k], j + dy[k], visited, grid))
            {
                visited[i + dx[k]][j + dy[k]] = true;
                q.emplace(make_pair(i + dx[k], j + dy[k]));
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int res = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] and grid[i][j] == '1')
            {
                numIslandsUsingBFS(i, j, visited, grid);
                res++;
            }
        }
    }

    return res;
}

void countIslandsUsingDFS(int si, int sj,
                          vector<int> &dx,
                          vector<int> &dy,
                          vector<vector<bool>> &visited,
                          vector<vector<char>> &graph)
{

    visited[si][sj] = true;

    for (int k = 0; k < 8; k++)
        if (isSafe(si + dx[k], sj + dy[k], visited, graph))
            countIslandsUsingDFS(si + dx[k], sj + dy[k], dx, dy, visited, graph);
}

int countIslands(vector<vector<char>> &grid)
{
    int res = 0;
    vector<int> dx = {0, 0, -1, 1, -1, -1, 1, 1};
    vector<int> dy = {-1, 1, 0, 0, -1, 1, -1, 1};
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] and grid[i][j] == '1')
            {
                numIslandsUsingBFS(i, j, visited, grid);
                res++;
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<char>> graph = {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}};
    // int count = numIslands(graph);
    int count = countIslands(graph);
    cout << "Number of Islands: " << count << "\n";

    return 0;
}