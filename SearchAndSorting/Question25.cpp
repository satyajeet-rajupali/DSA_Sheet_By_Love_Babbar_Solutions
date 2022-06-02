#include <bits/stdc++.h>
using namespace std;

int isValid(vector<int> trees, int N, int M, int H)
{
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        if (trees[i] > H)
            len += (trees[i] - H);
        if (len >= M)
            return true;
    }

    if (len >= M)
        return true;
    return false;
}

void solve(vector<int> trees, int N, int M)
{
    sort(trees.begin(), trees.end());
    int start = trees[0];
    int end = trees[N - 1];
    int ans;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (isValid(trees, N, M, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> trees(N);
    for (int i = 0; i < N; i++)
        cin >> trees[i];
    solve(trees, N, M);
    return 0;
}
