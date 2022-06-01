#include <bits/stdc++.h>
using namespace std;

void solve(vector<pair<long long int, long long int>> &vp, long long int k, long long int idx)
{
    long long int ans = -1;
    for (long long int i = 0; i <= idx; i++)
    {
        if ((vp[i].second - vp[i].first + 1) >= k)
        {
            ans = (k + vp[i].first) - 1;
            cout << ans << "\n";
            return;
        }
        else
        {
            k = k - (vp[i].second - vp[i].first + 1);
        }
    }
    cout << ans << "\n";
}

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int N, Q;
        cin >> N >> Q;

        vector<pair<long long int, long long int>> vp;

        for (long long int i = 0; i < N; i++)
        {
            long long int A, B;
            cin >> A >> B;
            vp.push_back({A, B});
        }

        // Sorting the pair
        sort(vp.begin(), vp.end());

        // Code to merge the sorted intervals that overlaps
        long long int idx = 0;

        for (long long int i = 1; i < vp.size(); i++)
        {
            if (vp[idx].second >= vp[i].first)
            {
                vp[idx].second = max(vp[i].second, vp[idx].second);
            }
            else
            {
                idx++;
                vp[idx] = vp[i];
            }
        }

        while (Q--)
        {
            long long int q;
            cin >> q;
            solve(vp, q, idx);
        }
    }

    return 0;
}