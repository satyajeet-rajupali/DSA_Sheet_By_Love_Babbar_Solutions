#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int L, int P, int T)
{
    int time(0), count(0);
    for (int i = 0; i < L; i++)
    {
        time = arr[i];
        int j = 2;
        while (time <= T)
        {
            count++;
            time += (arr[i] * j);
            j++;
        }
        if (count >= P)
            return true;
    }
    return false;
}

int MinTime(int arr[], int L, int P)
{
    int start = 0;
    int n = 1000;
    int R = 8;
    int end = R * ((n * (n + 1)) / 2);
    int ans;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (isValid(arr, L, P, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int P, L;
        cin >> P >> L;
        int ranks[L];
        for (int i = 0; i < L; i++)
            cin >> ranks[i];
        int ans = MinTime(ranks, L, P);
        cout << ans << "\n";
    }

    return 0;
}