#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> ans)
{

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int row = grid.size();
    int col = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> ans(row, vector<int>(col, INT32_MAX));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;

        if ((i - 1) >= 0 and ans[i][j] + 1 < ans[i - 1][j])
        {
            ans[i - 1][j] = ans[i][j] + 1;
            q.push({i - 1, j});
        }

        if ((j - 1) >= 0 and ans[i][j] + 1 < ans[i][j - 1])
        {
            ans[i][j - 1] = ans[i][j] + 1;
            q.push({i, j - 1});
        }

        if ((i + 1) < row and ans[i][j] + 1 < ans[i + 1][j])
        {
            ans[i + 1][j] = ans[i][j] + 1;
            q.push({i + 1, j});
        }

        if ((j + 1) < col and ans[i][j] + 1 < ans[i][j + 1])
        {
            ans[i][j + 1] = ans[i][j] + 1;
            q.push({i, j + 1});
        }
        q.pop();
    }

    return ans;
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 1},
                                {1, 1, 0},
                                {1, 0, 0}};

    cout << "Elements in grid:\n";
    display(grid);

    vector<vector<int>> ans = nearest(grid);

    if (ans.empty())
    {
        cout << "Something is wrong\n";
    }
    else
    {
        cout << "Elements in the ans:\n";
        display(ans);
    }

    return 0;
}