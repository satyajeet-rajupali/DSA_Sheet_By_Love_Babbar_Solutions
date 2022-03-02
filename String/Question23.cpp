#include <bits/stdc++.h>
using namespace std;

int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool search2D(vector<vector<char>> &grid, int row, int col,
              string word, int row_max, int col_max)
{
    if (grid[row][col] != word[0])
        return false;

    int len = word.length();

    for (int i = 0; i < 8; i++)
    {

        int k, rd = row + x[i], cd = col + y[i];

        for (k = 1; k < len; k++)
        {
            if (rd >= row_max or rd < 0 or cd >= col_max or cd < 0)
                break;

            if (grid[rd][cd] != word[k])
                break;

            rd += x[i];
            cd += y[i];
        }

        if (k == len)
            return true;
    }

    return false;
}

vector<vector<int>> searchWord(vector<vector<char>> &grid, string &word)
{
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<int>> ans;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (search2D(grid, r, c, word, R, C))
                ans.push_back({r, c});
        }
    }
    return ans;
}

int main()
{
    string word = "MAGIC";
    vector<vector<char>> grid = {{'B', 'B', 'A', 'B', 'B', 'M'},
                                 {'C', 'B', 'M', 'B', 'B', 'A'},
                                 {'I', 'B', 'A', 'B', 'B', 'G'},
                                 {'G', 'O', 'Z', 'B', 'B', 'I'},
                                 {'A', 'B', 'B', 'B', 'B', 'C'},
                                 {'M', 'C', 'I', 'G', 'A', 'M'}};
    vector<vector<int>> ans = searchWord(grid, word);
    cout << "Elements in ans:\n";
    for (int r = 0; r < ans.size(); r++)
    {
        for (int c = 0; c < ans[0].size(); c++)
        {
            cout << ans[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}