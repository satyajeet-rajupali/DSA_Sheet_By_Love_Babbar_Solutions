#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{

    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp.insert(pair<int, int>(a1[i], 1));

    int sz1 = mp.size();

    for (int i = 0; i < m; i++)
        mp.insert(pair<int, int>(a2[i], 1));

    int sz2 = mp.size();

    if (sz2 <= sz1)
        return "Yes";

    return "No";
}

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1, 9};

    if (isSubset(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0])) == "Yes")
        cout << "Subset\n";
    else
        cout << "Not a Subset\n";
    return 0;
}