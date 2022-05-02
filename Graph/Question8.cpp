#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int x;
    int y;
    cell() {}
    cell(int x, int y) : x(x), y(y)
    {
    }
};

class Solution
{
public:
    void displayImage(vector<vector<int>> &image)
    {

        for (int i = 0; i < image.size(); i++)
        {
            for (int j = 0; j < image[i].size(); j++)
            {
                cout << image[i][j] << " ";
            }
            cout << "\n";
        }
    }
    bool isSafe(int x, int y, int M, int N)
    {
        if (x == -1 or y == -1 or x >= M or y >= N)
            return false;
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        cell t;

        queue<cell> q;
        int c = image[sr][sc];
        int M = image.size();
        int N = image[0].size();

        vector<vector<bool>> visited(image.size(), vector<bool>(image.size(), false));
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        q.emplace(cell(sr, sc));
        int x, y;

        while (!q.empty())
        {
            t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                x = t.x + dx[i];
                y = t.y + dy[i];

                if (isSafe(x, y, M, N) and !visited[x][y] and image[x][y] == c)
                {
                    visited[x][y] = true;
                    image[x][y] = newColor;
                    q.emplace(cell(x, y));
                }
            }
        }
        return image;
    }
};

int main()
{
    vector<vector<int>> image =
        {{0, 0, 0},
         {0, 0, 0}};

    Solution s;
    cout << "old Image:\n";
    s.displayImage(image);
    image = s.floodFill(image, 0, 0, 2);
    cout << "New Image:\n";
    s.displayImage(image);

    return 0;
}