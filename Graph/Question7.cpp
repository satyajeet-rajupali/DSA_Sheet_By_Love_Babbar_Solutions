#include <bits/stdc++.h>
using namespace std;

bool isSafe(int c, int r, int n, vector<vector<bool>> &visited)
{
    if (r < 1 or c < 1 or r == n or c == n or visited[c][r])
        return false;
    return true;
}

struct cell
{
    int x;
    int y;
    int dis;
    cell() {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis)
    {
    }
};

bool isSafe(int r, int c, int N)
{
    if (r >= 1 and r <= N and c >= 1 and c <= N)
        return true;
    return false;
}
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    vector<int> dx = {-2, -1, 1, 2, -2, -1, 1, 2};
    vector<int> dy = {-1, -2, -2, -1, 1, 2, 2, 1};

    int x, y, tx, ty, tdis;
    // cell t;
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    queue<pair<int, pair<int, int>>> q;
    pair<int, pair<int, int>> t;
    q.emplace(make_pair(0, make_pair(KnightPos[0], KnightPos[1])));
    visited[KnightPos[0]][KnightPos[1]] = true;

    while (!q.empty())
    {
        tdis = q.front().first;
        tx = q.front().second.first;
        ty = q.front().second.second;
        q.pop();

        if (tx == TargetPos[0] and ty == TargetPos[1])
            return tdis;

        for (int i = 0; i < 8; i++)
        {
            x = tx + dx[i];
            y = ty + dy[i];

            if (isSafe(x, y, N) and !visited[x][y])
            {
                visited[x][y] = true;
                q.emplace(make_pair(tdis + 1, make_pair(x, y)));
            }
        }
    }
}

int main()
{
    vector<int> kp = {4, 5};
    vector<int> tp = {1, 1};
    int N = 6;
    cout << "Min Steps: " << minStepToReachTarget(kp, tp, 6) << "\n";

    return 0;
}