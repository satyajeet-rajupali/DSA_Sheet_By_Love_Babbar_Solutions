#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> stallLoc, int nc, int minDist)
{
    int lastLoc = stallLoc[0];
    int cnt = 1;
    int N = stallLoc.size();
    for (int i = 1; i < N; i++)
    {
        if ((stallLoc[i] - lastLoc) >= minDist)
        {
            cnt++;
            lastLoc = stallLoc[i];
            if (cnt == nc)
                return true;
        }
    }
    return false;
}

void minLargestDistance(vector<int> stallLoc, int nc)
{
    sort(stallLoc.begin(), stallLoc.end());
    int N = stallLoc.size();
    int res = -1;
    int low = 1, high = stallLoc[N - 1] - stallLoc[0];

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (isPossible(stallLoc, nc, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, C;
        cin >> N >> C;
        vector<int> stallLoc;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            stallLoc.push_back(x);
        }
        minLargestDistance(stallLoc, C);
    }
    return 0;
}