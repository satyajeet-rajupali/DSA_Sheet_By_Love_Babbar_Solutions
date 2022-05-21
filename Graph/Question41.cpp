#include <bits/stdc++.h>
using namespace std;

void matrixMultiplication(vector<vector<int>> &m1,
                          vector<vector<int>> &m2,
                          vector<vector<int>> &m3)
{

    for (int i = 0; i < m1.size(); i++)
    {
        for (int j = 0; j < m1[0].size(); j++)
        {
            m3[i][j] = 0;
            for (int k = 0; k < m1[0].size(); k++)
            {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int getTrace(vector<vector<int>> m2)
{
    int trace = 0;
    for (int i = 0; i < m2.size(); i++)
        trace += m2[i][i];

    return trace;
}

// For undirected graphs only
void trainglesInGraph(vector<vector<int>> graph)
{
    vector<vector<int>> ax1(graph.size(), vector<int>(graph.size(), 0));
    vector<vector<int>> ax2(graph.size(), vector<int>(graph.size(), 0));

    matrixMultiplication(graph, graph, ax1);
    matrixMultiplication(graph, ax1, ax2);

    int trace = getTrace(ax2);
    int nT = trace / 6;
    cout << "Number of Triangles in the graph: " << nT << "\n";
}

void trainglesInGraph1(vector<vector<int>> graph, bool isD)
{
    int n = graph.size();
    int countTri = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (graph[i][j] and graph[j][k] and graph[k][i])
                    countTri++;
            }
        }
    }

    int nT = isD ? countTri / 3 : countTri / 6;
    cout << "Number of Triangles in graph " << nT << "\n";
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 0},
                                 {1, 0, 1, 1},
                                 {1, 1, 0, 1},
                                 {0, 1, 1, 0}};
    // trainglesInGraph(graph);
    trainglesInGraph1(graph, false);

    vector<vector<int>> graph1 = {{0, 0, 1, 0},
                                  {1, 0, 0, 1},
                                  {0, 1, 0, 0},
                                  {0, 0, 1, 0}};

    trainglesInGraph1(graph1, true);

    return 0;
}