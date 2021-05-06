#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    return (gap / 2) + (gap % 2);
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    int i, j;
    int gap = nextGap(m + n);

    while (gap >= 1)
    {

        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[i + gap])
            {
                swap(arr1[i], arr1[i + gap]);
            }
        }
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
        }
        if (j < m)
        {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
            {
                if (arr2[j] > arr2[j + gap])
                {
                    swap(arr2[j], arr2[j + gap]);
                }
            }
        }

        gap = nextGap(gap);
    }

    cout << "Elements in the merged array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
}

int main()
{
    int n = 4, m = 5;
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};

    merge(arr1, arr2, n, m);

    cout << "Elements in the merged array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }

    cout << "\n";

    return 0;
}