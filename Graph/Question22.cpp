#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

void flloydWarshallAlgorithm(vector<vector<int>> &graph, int n)
{

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // if (graph[i][j] != INF and graph[k][j] != INF) to be used in case of Negative Weights
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    cout << "Distances:\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] != INF)
                cout << graph[i][j] << " ";
            else
                cout << "I"
                     << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // vector<vector<int>> graph = {
    //     // 0  1     2    3    4    5   6
    //     {0, INF, INF, INF, INF, INF, INF},
    //     {INF, 0, 1, INF, INF, 3, INF},
    //     {INF, INF, 0, 2, 2, 1, INF},
    //     {INF, INF, INF, 0, INF, 2, INF},
    //     {INF, INF, INF, INF, 0, 3, 1},
    //     {INF, INF, INF, INF, INF, 0, 2},
    //     {INF, INF, INF, INF, INF, INF, 0}};

    vector<vector<int>> graph = {{0, INF, INF, INF, INF},
                                 {INF, 0, 1, INF, INF},
                                 {INF, INF, 0, -1, INF},
                                 {INF, INF, INF, 0, -1},
                                 {INF, -1, INF, INF, 0}};

    flloydWarshallAlgorithm(graph, 4);
    return 0;
}