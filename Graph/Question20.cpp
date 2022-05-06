#include <bits/stdc++.h>
using namespace std;

// What if graph is not complete?
// Follow the given procedure :-
// STEP 1: Create Adjacency Matrix for the given graph.
// STEP 2: Replace all the diagonal elements with the degree of nodes. For eg. element at (1,1) position of adjacency matrix will be replaced by the degree of node 1, element at (2,2) position of adjacency matrix will be replaced by the degree of node 2, and so on.
// STEP 3: Replace all non-diagonal 1’s with -1.
// STEP 4: Calculate co-factor for any element.
// STEP 5: The cofactor that you get is the total number of spanning tree for that graph.

int mstCount(vector<int> adj[], int n)
{
    int degree[n];
    for (int i = 1; i < n; i++)
        degree[i] = adj[i].size();

    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Step-1, Step-2, Step-3
    for (int i = 1; i < n; i++)
    {
        graph[i][i] = degree[i];
        for (auto it : adj[i])
            if (i != it)
                graph[i][it] = -1;
    }

    // Step-4
    return (graph[2][2] * ((graph[3][3] * graph[4][4]) - (graph[3][4] * graph[4][3])) -
            graph[2][3] * ((graph[3][2] * graph[4][4]) - (graph[4][2] * graph[3][4])) +
            graph[2][4] * ((graph[3][2] * graph[4][3]) - (graph[4][2] * graph[3][3])));
}

int main()
{
    int n = 5;
    vector<int> adj[n];
    adj[1].push_back(4);
    adj[1].push_back(3);

    adj[2].push_back(3);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);

    adj[4].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(3);

    cout << "Number of MST: " << mstCount(adj, n) << "\n";

    return 0;
}