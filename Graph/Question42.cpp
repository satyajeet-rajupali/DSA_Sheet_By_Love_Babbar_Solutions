#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> amount)
{
    return max_element(amount.begin(), amount.end()) - amount.begin();
}

int getMin(vector<int> amount)
{
    return min_element(amount.begin(), amount.end()) - amount.begin();
}

void moneyFlowUtil(vector<int> &amount)
{
    int maxcredit = getMax(amount);
    int maxdebit = getMin(amount);

    if (amount[maxcredit] == 0 and amount[maxdebit] == 0)
        return;

    int mn = min(-amount[maxdebit], amount[maxcredit]);
    amount[maxcredit] -= mn;
    amount[maxdebit] += mn;

    cout << "Person " << maxdebit << " pays " << mn << " to " << maxcredit << "\n";
    moneyFlowUtil(amount);
}

void moneyFlow(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> amount(graph.size(), 0);
    for (int p = 0; p < n; p++)
        for (int i = 0; i < n; i++)
            amount[p] += (graph[i][p] - graph[p][i]);

    moneyFlowUtil(amount);
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0},
    };

    moneyFlow(graph);
    return 0;
}