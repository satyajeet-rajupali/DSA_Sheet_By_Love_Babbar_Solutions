#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
{
    // Code here.
    sort(v.begin(), v.end());
    int sz = v.size();
    if (sz % 2 != 0)
        return v[sz / 2];
    else
        return (v[sz / 2] + v[(sz / 2) - 1]) / 2;
}

int main()
{
    vector<int> vec = {90, 100, 78, 89, 67};
    cout << "Median: " << find_median(vec);
    return 0;
}