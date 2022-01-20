#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void merger(int vec1[], int vec2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
    while (i <= k && j < m)
    {
        if (vec1[i] < vec2[j])
            i++;
        else
        {
            swap(vec2[j++], vec1[k--]);
        }
    }

    sort(vec1, vec1 + n);
    sort(vec2, vec2 + m);

    display(vec1, n);
    display(vec2, m);
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    merger(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]));

    return 0;
}