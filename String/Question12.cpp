#include <bits/stdc++.h>
using namespace std;

int solveWordWrap(vector<int> nums, int k)
{
    // Code here
    int n = nums.size();
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        arr[i] = nums[i - 1];

    int space[n + 1][n + 1], ls[n + 1][n + 1];
    int c[n + 1], p[n + 1];

    for (int i = 1; i <= n; i++)
    {
        space[i][i] = k - arr[i];
        for (int j = i + 1; j <= n; j++)
        {
            space[i][j] = space[i][j - 1] - arr[j] - 1;
        }
    }

    // cout << "Matrix SPace:\n";
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         cout << space[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {

            if (space[i][j] < 0)
                ls[i][j] = INT_MAX;
            else if (j == n and space[i][j] >= 0)
                ls[i][j] = 0;
            else
                ls[i][j] = space[i][j] * space[i][j];
        }
    }

    // cout << "Matrix ls:\n";
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         cout << ls[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    c[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        c[i] = INT_MAX;
        for (int j = 1; j <= i; j++)
        {
            if (c[j - 1] != INT_MAX and ls[j][i] != INT_MAX and c[j - 1] + ls[j][i] < c[i])
            {
                c[i] = c[j - 1] + ls[j][i];
                p[i] = j;
            }
        }
    }
    // cout << "p:\n";
    // for (int j = 0; j < n + 1; j++)
    // {
    //     cout << p[j] << " ";
    // }
    // cout << "\n";

    // cout << "c:\n";
    // for (int j = 0; j < n + 1; j++)
    // {
    //     cout << c[j] << " ";
    // }
    // cout << "\n";

    return c[n];
}

int main()
{
    vector<int> v = {3, 2, 2};
    cout << "Min cost:" << solveWordWrap(v, 4);
    return 0;
}