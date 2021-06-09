#include <bits/stdc++.h>

using namespace std;

void showMap(map<int, int> mp)
{
    cout << "Elements in map:\n";
    cout << "\tKEY\tVALUE\n";
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << "\t" << it->first << "\t" << it->second << "\n";
    }
}

string isSubset(int a1[], int a2[], int n, int m)
{

    map<int,int> mp;

    for (int i = 0; i < n; i++)
    {
        mp.insert(pair<int, int>(a1[i], 1));
    }

    showMap(mp);

    int sz1 = mp.size();

    for (int i = 0; i < m; i++)
    {
        mp.insert(pair<int, int>(a2[i], 1));
    }

    showMap(mp);


    int sz2 = mp.size();

    if (sz2 <= sz1)
    {
        return "YES";
    }

    return "No";
}

int main()
{

    // int a1[] = {10, 5, 2, 23, 19};
    // int a2[] = {19, 5, 3};

    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};

    cout << isSubset(a1, a2, sizeof(a1) / sizeof(a1[0]), sizeof(a2) / sizeof(a2[0]));

    return 0;
}