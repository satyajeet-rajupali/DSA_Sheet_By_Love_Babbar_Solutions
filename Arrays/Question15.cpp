#include <bits/stdc++.h>
using namespace std;

int getCountInversion(int arr[], int n)
{

    multiset<int> ms1;
    ms1.insert(arr[0]);

    int invcount = 0;

    multiset<int>::iterator it;

    for (int i = 1; i < n; i++)
    {

        ms1.insert(arr[i]);
        it = ms1.upper_bound(arr[i]);
        invcount = invcount + distance(it, ms1.end());
    }

    return invcount;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    cout << "Inversion Count: "
         << getCountInversion(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
    return 0;
}