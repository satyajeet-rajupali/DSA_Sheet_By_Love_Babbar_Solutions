#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define mp make_pair

void solve(int a, int b, int target)
{
    vector<pii> path;
    bool isSolvable = false;
    map<pii, bool> visited;
    queue<pii> q;

    q.emplace(mp(0, 0));

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        if (visited[u])
            continue;

        if (u.first > a or u.second > b or u.first < 0 or u.second < 0)
            continue;

        visited[u] = true;
        path.push_back(u);

        if (u.first == target or u.second == target)
        {
            isSolvable = true;

            if (u.first == target)
                if (u.second != 0)
                    path.push_back(mp(u.first, 0));

            if (u.second == target)
                if (u.first != 0)
                    path.push_back(mp(0, u.second));

            cout << "Path:\n";
            for (int i = 0; i < path.size(); i++)
                cout << "{" << path[i].first << ", " << path[i].second << "} ";
            cout << "\n";
        }

        q.emplace(mp(u.first, b));
        q.emplace(mp(a, u.second));

        for (int ap = 0; ap < max(a, b); ap++)
        {
            int c, d;

            c = u.first + ap;
            d = u.second - ap;

            if (c == a or (d == 0 and d >= 0))
                q.emplace(mp(c, d));

            d = u.second + ap;
            c = u.first - ap;

            if (d == b or (c == 0 and c >= 0))
                q.emplace(mp(c, d));
        }

        q.emplace(mp(a, 0));
        q.emplace(mp(0, b));
    }

    if (!isSolvable)
        cout << "No Solution Possible\n";
}

int main()
{
    solve(4, 3, 2);
    return 0;
}