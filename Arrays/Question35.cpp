#include <bits/stdc++.h>
using namespace std;

int medianOfTwoArrayDifferentSizes(int arr1[], int arr2[], int n1, int n2)
{

    int i = 0, j = 0;
    int m1 = -1, m2 = -1;
    int count;

    for (count = 0; count <= (n1 + n2) / 2; count++)
    {
        m2 = m1;
        if (i != n1 && j != n2)
            m1 = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
        else if (i < n1)
            m1 = arr1[i++];
        else //(j < n2)
            m1 = arr2[j++];
    }

    if ((n1 + n2) % 2 != 0)
        return m1;
    else
        return (m1 + m2) / 2;
}

int main()
{
    int arr1[] = {900};
    int arr2[] = {5, 8, 10, 20};

    cout << "Median: " << medianOfTwoArrayDifferentSizes(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]));

    return 0;
}