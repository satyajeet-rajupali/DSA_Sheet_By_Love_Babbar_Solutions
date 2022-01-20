#include <bits/stdc++.h>
using namespace std;

void Union(int arr1[], int size1, int arr2[], int size2)
{

    int i = 0, j = 0, k = 0;
    int arr3[size1 + size2];

    while (i < size1 && j < size2)
    {
        if (arr1[i] == arr2[j])
        {
            arr3[k++] = arr1[i++];
            j++;
        }
        else if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else if (arr1[i] > arr2[j])
            arr3[k++] = arr2[j++];
    }

    for (; i < size1; i++)
        arr3[k++] = arr1[i];

    for (; j < size2; j++)
        arr3[k++] = arr2[j];

    cout << "Resultant Array:\n";
    for (int l = 0; l < k; l++)
        cout << arr3[l] << " ";
    cout << "\n";
}

void Intersection(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0, k = 0;
    int arr3[size1 + size2];

    while (i < size1 && j < size2)
    {
        if (arr1[i] == arr2[j])
        {
            arr3[k++] = arr1[i++];
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
    }

    cout << "Resultant Array:\n";
    for (int l = 0; l < k; l++)
        cout << arr3[l] << " ";
    cout << "\n";
}

int main()
{
    int arr1[] = {85, 25, 1, 32, 54, 6};
    int arr2[] = {85, 2};

    // Union(arr1, sizeof(arr1) / sizeof(arr1[0]), arr2, sizeof(arr2) / sizeof(arr2[0]));
    Intersection(arr1, sizeof(arr1) / sizeof(arr1[0]), arr2, sizeof(arr2) / sizeof(arr2[0]));

    return 0;
}