#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Graph
{
public:
    Node *ls;
    int n;
    Graph(int n)
    {
        this->n = n;
        ls = new Node[n];
        for (int i = 0; i < n; i++)
            ls[i].next = nullptr;
    }
    void add_edge(int u, int v);
    void printGraph();
    void BFSTraversal(int u);
    void DFSTraversal(int u, vector<bool> &visited);
};

void Graph::DFSTraversal(int u, vector<bool> &visited)
{
    if (!visited[u])
    {
        cout << u << " ";
        visited[u] = true;
        Node *p = ls[u].next;
        while (p)
        {
            DFSTraversal(p->data, visited);
            p = p->next;
        }
    }
}

void Graph::printGraph()
{
    cout << "Adjacency List:\n";
    for (int i = 1; i < n; i++)
    {
        cout << i << ":";
        Node *p = ls[i].next;
        while (p)
        {
            cout << "-->[" << i << "," << p->data << "]";
            p = p->next;
        }
        cout << "\n";
    }
}

void Graph::add_edge(int u, int v)
{
    if (!ls[u].next)
    {
        Node *t = new Node;
        t->data = v;
        t->next = nullptr;
        ls[u].next = t;
        return;
    }
    else
    {
        Node *p = ls[u].next;
        while (p->next)
            p = p->next;
        Node *t = new Node;
        t->data = v;
        t->next = nullptr;
        p->next = t;
        return;
    }
}

void Graph::BFSTraversal(int u)
{
    queue<int> q;
    vector<bool> visited(n, false);
    visited[u] = true;
    cout << u << " ";
    q.emplace(u);

    while (!q.empty())
    {
        u = q.front();
        q.pop();

        Node *p = ls[u].next;
        while (p)
        {
            if (p and !visited[p->data])
            {
                q.emplace(p->data);
                visited[p->data] = true;
                cout << p->data << " ";
            }
            p = p->next;
        }
    }

    cout << "\n";
    return;
}

int main()
{
    Graph g(8);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.add_edge(3, 2);
    g.add_edge(3, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 1);
    g.add_edge(4, 2);
    g.add_edge(4, 5);
    g.add_edge(5, 3);
    g.add_edge(5, 4);
    g.add_edge(5, 6);
    g.add_edge(5, 7);
    g.add_edge(6, 5);
    g.add_edge(7, 5);

    g.printGraph();

    cout << "BFS Traversal:\n";
    g.BFSTraversal(1);

    vector<bool> visited(g.n, false);
    cout << "DFS Traversal:\n";
    g.DFSTraversal(1, visited);
    cout << "\n";

    return 0;
}