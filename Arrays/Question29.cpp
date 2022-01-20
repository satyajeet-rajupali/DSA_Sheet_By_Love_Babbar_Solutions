#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> &a, long long n, long long m)
{

    // if there are no chocolates or number
    // of students is 0
    if (m == 0 || n == 0)
        return 0;

    // Sort the given packets
    sort(a.begin(), a.end());

    // Number of students cannot be more than
    // number of packets
    if (n < m)
        return -1;

    // Largest number of chocolates
    long long min_diff = LONG_MAX;

    // Find the subarray of size m such that
    // difference between last (maximum in case
    // of sorted) and first (minimum in case of
    // sorted) elements of subarray is minimum.

    for (long long i = 0; i + m - 1 < n; i++)
    {
        long long diff = a[i + m - 1] - a[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main()
{
    vector<long long> container = {3, 4, 1, 9, 56, 7, 9, 12};
    long long m = 5;
    cout << "Min Difference: " << findMinDiff(container, container.size(), m) << "\n";

    return 0;
}