#include <bits/stdc++.h>
using namespace std;

int inSequence(int A, int B, int C)
{
    // code here
    if (A == B)
        return 1;

    double l = ((double)(B - A)) / ((double)C);
    if (l < 0)
        return 0;
    int l1 = l;
    int k = l;

    return k == l;
}

// Missing Number in AP
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (inSequence(A, B, C))
        cout << "Missing Term\n";
    else
        cout << "Not a missing Term\n";
    return 0;
}