#include <bits/stdc++.h>
using namespace std;

int timer = 1;
vector<int> inTime;
vector<int> outTime;

void dfs(int src, int par, int &timer, vector<int> adj[])
{
    inTime[src] = timer++;

    for (auto it : adj[src])
    {
        if (it != par)
            dfs(it, src, timer, adj);
    }
    outTime[src] = timer++;
}

bool check(int x, int y)
{
    if (inTime[x] > inTime[y] and outTime[x] < outTime[y])
        return true;
    return false;
}

int main()
{
    int N;
    cout << "Enter the number of Houses:\n";
    cin >> N;
    vector<int> adj[N + 1];
    inTime.resize(N + 1);
    outTime.resize(N + 1);

    for (int i = 1; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    dfs(1, 0, timer, adj);

    int Q;
    cout << "Enter queries:\n";
    cin >> Q;
    int dir, o, b;
    for (int i = 0; i < Q; i++)
    {
        int dir, x, y;
        cin >> dir >> x >> y;

        if (!check(x, y) and !check(y, x))
        {
            cout << "NO\n";
            continue;
        }

        if (dir == 0)
        {
            if (check(y, x))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            if (check(x, y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}