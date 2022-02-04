#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N,
                                            long long int K)
{
    queue<long long> q;
    vector<long long> ans;

    for (long long i = 0; i < K - 1; i++)
        if (A[i] < 0)
            q.push(A[i]);

    for (long long i = K - 1; i < N; i++)
    {

        if (A[i] < 0)
            q.push(A[i]);
        if (!q.empty())
        {
            ans.push_back(q.front());
            if (q.front() == A[i - K + 1])
                q.pop();
        }
        else
            ans.push_back(0);
    }
    return ans;
}

int main()
{
    long long int A[] = {-8, 2, 3, -6, 10};
    long long int N = sizeof(A) / sizeof(A[0]);
    long long int K = 2;

    vector<long long> ans = printFirstNegativeInteger(A, N, 2);
    cout << "Elements in the ans:\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}