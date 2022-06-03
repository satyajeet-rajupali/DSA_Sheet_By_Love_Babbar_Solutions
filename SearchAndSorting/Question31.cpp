#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int m, n;
        cin >> m;
        if (m == 0)
            break;
        else
        {
            int arr1[m];
            for (int x = 0; x < m; x++)
                cin >> arr1[x];

            cin >> n;
            int arr2[n];
            for (int y = 0; y < n; y++)
                cin >> arr2[y];

            int i = 0, j = 0;
            int s1 = 0, s2 = 0;
            int ans = 0;
            while (i < m and j < n)
            {
                if (arr1[i] < arr2[j])
                    s1 += arr1[i++];
                else if (arr1[i] > arr2[j])
                    s2 += arr2[j++];
                else
                {
                    ans += (max(s1, s2) + arr1[i]);
                    s1 = 0;
                    s2 = 0;
                    i++;
                    j++;
                }
            }

            while (i < m)
                s1 += arr1[i++];

            while (j < n)
                s2 += arr2[j++];
            ans += max(s1, s2);

            cout << ans << "\n";
        }
    }

    return 0;
}