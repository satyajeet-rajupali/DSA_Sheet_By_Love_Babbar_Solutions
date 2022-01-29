#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
int celebrity1(vector<vector<int>> &M, int n)
{
    // code here
    int in[n] = {0};
    int out[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1 and i!=j)
            {
                in[j]++;
                out[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (in[i] == n - 1 and out[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

// TC: O(N), SC: O(1)
int celebrity2(vector<vector<int>> &M, int n)
{
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (M[c][i] == 1)
            c = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i!=c and (M[c][i] == 1 or M[i][c] == 0))
            return -1;
    }

    return c;
}

int main()
{
    vector<vector<int>> M = {{0, 1, 0},
                             {0, 1, 0},
                             {0, 1, 0}};
    int ans1 = celebrity1(M, M.size());
    if (ans1 == -1)
        cout << "No person is celebrity1.\n";
    else
        cout << "Celebrity1 is Person-" << ans1 + 1 << ".\n";

    int ans2 = celebrity2(M, M.size());
    if (ans2 == -1)
        cout << "No person is celebrity2.\n";
    else
        cout << "Celebrity2 is Person-" << ans2 + 1 << ".\n";

    return 0;
}