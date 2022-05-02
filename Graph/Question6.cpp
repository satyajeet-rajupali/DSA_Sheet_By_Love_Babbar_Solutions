#include <bits/stdc++.h>
using namespace std;

bool isSafe(int r, int c, int n, vector<vector<bool>> &visited, vector<vector<int>> &m)
{
    if (r == -1 or c == -1 or r == n or c == n or visited[r][c] or m[r][c] == 0)
        return false;
    return true;
}

void findPathUtil(vector<vector<int>> &m, int n, vector<vector<bool>> &visited, int r, int c, vector<string> &ans, string path)
{
    if (r == -1 or c == -1 or r == n or c == n or visited[r][c] or m[r][c] == 0)
        return;

    if (r == n - 1 and c == n - 1)
    {
        cout << "Working-4\n";
        ans.push_back(path);
        return;
    }

    visited[r][c] = true;

    // Moving Leftward
    if (isSafe(r, c - 1, n, visited, m))
    {
        path.push_back('L');
        findPathUtil(m, n, visited, r, c - 1, ans, path);
        path.pop_back();
    }

    // Moving Rightward
    if (isSafe(r, c + 1, n, visited, m))
    {
        path.push_back('R');
        findPathUtil(m, n, visited, r, c + 1, ans, path);
        path.pop_back();
    }

    // Moving UpWard
    if (isSafe(r - 1, c, n, visited, m))
    {
        path.push_back('U');
        findPathUtil(m, n, visited, r - 1, c, ans, path);
        path.pop_back();
    }

    // Moving Downward
    if (isSafe(r + 1, c, n, visited, m))
    {
        path.push_back('D');
        findPathUtil(m, n, visited, r + 1, c, ans, path);
        path.pop_back();
    }

    visited[r][c] = false;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    if (m[0][0] == 0)
        return ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // unordered_map<string, bool> visited;

    findPathUtil(m, n, visited, 0, 0, ans, "");
    return ans;
}

void printPaths(vector<string> paths)
{
    cout << "Various Possible Paths:\n";
    for (auto path : paths)
        cout << path << "\n";
}

int main()
{

    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    vector<string> paths = findPath(maze, 4);
    if (paths.size() == 0)
        cout << "No path exists\n";
    else
        printPaths(paths);

    return 0;
}