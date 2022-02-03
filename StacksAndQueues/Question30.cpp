#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    queue<pair<int, int>> q;
    int count = 0;
    int row = grid.size();
    int col = grid[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    q.push({-1, -1});

    while (!q.empty())
    {
        /* code */
        int i = q.front().first;
        int j = q.front().second;

        if ((i == -1 and j == -1) and q.size() == 1)
        {
            q.pop();
            break;
        }
        else if ((i == -1 and j == -1) and q.size() > 1)
        {
            count++;
            q.pop();
            q.push({-1, -1});
        }
        else
        {
            if ((i - 1) >= 0 and grid[i - 1][j] == 1)
            {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }

            if ((j - 1) >= 0 and grid[i][j - 1] == 1)
            {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }

            if ((i + 1) < row and grid[i + 1][j] == 1)
            {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }

            if ((j + 1) < col and grid[i][j + 1] == 1)
            {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }

            q.pop();
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};

    int time = orangesRotting(grid);

    if (time == -1)
    {
        cout << "Couldn't rot all oranges.\n";
    }
    else
    {
        cout << "Time taken to rot all oranges: " << time << ".\n";
    }

    return 0;
}