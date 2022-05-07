#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int vertex;
    int distance;
    cell() {}
    cell(int v, int d)
    {
        vertex = v;
        distance = d;
    }
};

class Solution
{
    void getPos(int pos, int& x, int& y, int n){

        x = (pos - 1) / n;
        y = (pos - 1) % n;
        x = n - 1 - x;
        if(x % 2 == n % 2)
            y = n - 1 - y;
    }
public:
    void printMatrix(vector<int> mat)
    {
        cout << "Elements in the matrix\n";
        for (int i = 0; i < mat.size(); i++)
            cout << i << ":" << mat[i] << "\n";
        cout << "\n";
    }

    

    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        int n2 = n * n;

        vector<bool> visited(n2 + 1, false);
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        visited[1] = true;
        while (!q.empty())
        {
            int pos = q.front().first;
            int step = q.front().second;
            q.pop();

            if (pos == n2)
                return step;

            for (int i = 1; i <= 6 && pos + i <= n2; i++)
            {
                int next = pos + i;
                int x, y;
                getPos(next, x, y, n);
                if (board[x][y] != -1)
                    next = board[x][y];
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(make_pair(next, step + 1));
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> board = {
        {-1, -1},
        {-1, 1}};
    // {-1, -1, -1, -1, -1, -1},
    // {-1, -1, -1, -1, -1, -1},
    // {-1, -1, -1, -1, -1, -1},
    // {-1, 35, -1, -1, 13, -1},
    // {-1, -1, -1, -1, -1, -1},
    // {-1, 15, -1, -1, -1, -1}};
    Solution s;
    int ans = s.snakesAndLadders(board);
    cout << "\nMin Moves: " << ans << "\n";

    return 0;
}