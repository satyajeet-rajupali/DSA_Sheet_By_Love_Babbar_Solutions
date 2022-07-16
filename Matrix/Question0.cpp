#include <bits/stdc++.h>
using namespace std;

// void print Spiral elements
void printSpiralMatrix(vector<vector<int>> matrix, int m, int n)
{
    int minr = 0;
    int minc = 0;
    int maxr = matrix.size() - 1;
    int maxc = matrix[0].size() - 1;
    int count = 0;
    int toe = m * n;
    while (count < toe)
    {
        // Left wall
        for (int i = minr, j = minc; i <= maxr && count < toe; i++)
        {
            cout << matrix[i][j] << " ";
            count++;
        }
        minc++;

        // Bottom Wall
        for (int i = maxr, j = minc; j <= maxc && count < toe; j++)
        {
            cout << matrix[i][j] << " ";
            count++;
        }
        maxr--;

        // Right wall
        for (int i = maxr, j = maxc; i >= minr && count < toe; i--)
        {
            cout << matrix[i][j] << " ";
            count++;
        }
        maxc--;

        // Top Wall
        for (int i = minr, j = maxc; j >= minc && count < toe; j--)
        {
            cout << matrix[i][j] << " ";
            count++;
        }
        minr++;
    }
    cout << "\n";
    cout << "Count: " << count << "\n";
}

int main()
{
    //  6 x 6 matrix
    vector<vector<int>> matrix = {{11, 12, 13, 14, 15, 16},
                                  {21, 22, 23, 24, 25, 26},
                                  {31, 32, 33, 34, 35, 36},
                                  {41, 42, 43, 44, 45, 46},
                                  {51, 52, 53, 54, 55, 56},
                                  {61, 62, 63, 64, 65, 66}};
    // 5 x  6 matrix
    vector<vector<int>> matrix1 = {{11, 12, 13, 14, 15, 16},
                                   {21, 22, 23, 24, 25, 26},
                                   {31, 32, 33, 34, 35, 36},
                                   {41, 42, 43, 44, 45, 46},
                                   {51, 52, 53, 54, 55, 56}};

    cout << "Sprial traversal of 6 x 6 matrix:\n";
    printSpiralMatrix(matrix, matrix.size(), matrix[0].size());

    cout << "Sprial traversal of 5 x 6 matrix:\n";
    printSpiralMatrix(matrix1, matrix1.size(), matrix1[0].size());

    return 0;
}