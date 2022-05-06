#include <bits/stdc++.h>
using namespace std;

void makeGraph(vector<pair<int, int>> &prerequisites, vector<unordered_set<int>> &graph)
{
    for (auto it : prerequisites)
    {
        int u = it.second;
        int v = it.first;
        graph[u].insert(v);
    }
}

bool checkCycle(int v, vector<bool> &visited, vector<bool> &dfsVisited, vector<unordered_set<int>> &graph)
{
    visited[v] = true;
    dfsVisited[v] = true;

    for (auto it : graph[v])
    {
        if (!visited[it])
        {
            if (checkCycle(it, visited, dfsVisited, graph))
                return true;
        }
        else if (dfsVisited[it] == true)
            return true;
    }

    dfsVisited[v] = false;

    return false;
}

bool checkFinish(int numTasks, vector<pair<int, int>> prereqisites)
{
    vector<unordered_set<int>> graph(numTasks);
    makeGraph(prereqisites, graph);

    vector<bool> visited(numTasks, false);
    vector<bool> dfsVisited(numTasks, false);

    for (int i = 0; i < numTasks; i++)
    {
        if (!visited[i] and checkCycle(i, visited, dfsVisited, graph))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<pair<int, int>> prerequisites;
    int numTasks = 4;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));

    if (checkFinish(numTasks, prerequisites))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}