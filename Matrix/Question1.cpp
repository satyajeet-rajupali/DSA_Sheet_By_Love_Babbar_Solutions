#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int i = 0;
    int j = matrix[0].size() - 1;
    while (j >= 0 and i <= (matrix.size() - 1))
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (target < matrix[i][j])
        {
            j--;
        }
        else if (target > matrix[i][j])
        {
            i++;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> v = {{1, 3, 5, 7},
                             {10, 11, 16, 20},
                             {23, 30, 34, 60}};

    if (searchMatrix(v, 13))
        cout << "Found!\n";
    else
        cout << "Not Found!\n";

    return 0;
}