#include <bits/stdc++.h>
using namespace std;

int kthSmallestElement(int arr[], int size, int k)
{

    set<int> s1;
    set<int>::iterator itr;

    for (int i = 0; i < size; i++)
        s1.emplace(arr[i]);

    itr = s1.begin();
    advance(itr, k - 1);

    return *itr;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "3rd smallest element: " << kthSmallestElement(arr, n, 4);

    return 0;
}