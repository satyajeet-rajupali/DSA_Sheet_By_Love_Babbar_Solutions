#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int *arr, int n, int k)
{

    sort(arr, arr + n);
    int x = 1, ans = (arr[n - 1] - arr[0]);

    while (arr[x] - k < 0)
        x++;
    for (; x < n - 1; x++)
    {
        int mn = min(arr[0] + k, arr[x] - k);
        int mx = max(arr[n - 1] - k, arr[x - 1] + k);
        ans = min(mx - mn, ans);
    }

    return ans;
}

int main()
{
    int arr[] = {3, 9, 12, 16, 20};
    int k = 3;
    cout << "Minimized Heights: "
         << getMinDiff(arr, sizeof(arr) / sizeof(arr[0]), k) << "\n";

    return 0;
}