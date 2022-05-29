#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
void merge(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0, k = m - 1;

    while (i <= k and j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
            swap(arr1[k--], arr2[j++]);
    }

    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    cout << "After Merging:\n";
    printArray(arr1, m);
    printArray(arr2, n);
}

int main()
{
    int N = 4, M = 5;
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0,
                  2,
                  6,
                  8,
                  9};
    merge(arr1, N, arr2, M);
    return 0;
}