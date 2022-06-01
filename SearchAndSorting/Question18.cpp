#include <iostream>
using namespace std;

void solve(int arr[], int n, int bp)
{
    int power(0), cnt(0);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= bp)
        {
            cnt++;
            power += arr[i];
        }
    }

    cout << cnt << " " << power << "\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int bp, q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> bp;
        solve(arr, n, bp);
    }

    return 0;
}