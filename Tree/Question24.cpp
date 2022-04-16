#include <bits/stdc++.h>
using namespace std;

int checkMirrorTree(int n, int e, int A[], int B[])
{
    unordered_map<int, stack<int>> mos;

    for (int i = 0; i < 2 * e; i += 2)
        mos[A[i]].emplace(A[i + 1]);

    for (int i = 0; i < 2 * e; i += 2)
    {
        if (mos[B[i]].top() != B[i + 1])
            return 0;
        mos[B[i]].pop();
    }
    return 1;
}

int main()
{
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 2, 1, 3};
    int e = 2;
    int n = 3;
    if (checkMirrorTree(n, e, A, B))
        cout << "Mirror of each other\n";
    else
        cout << "Doesn't mirror each other\n";

    return 0;
}