#include <bits/stdc++.h>
using namespace std;

void maxOfAllSubArrays(vector<int> v, int k)
{
    vector<int> ans;

    deque<int> dq;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() and dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() and v[dq.back()] <= v[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(v[dq.front()]);
    }

    cout << "Answer:\n";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
}

int main()
{
    vector<int> v = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k = 4;
    maxOfAllSubArrays(v, k);

    return 0;
}