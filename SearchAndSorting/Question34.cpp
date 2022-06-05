#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// TC: O(N^2)
void merge(int array[], int start, int mid, int end)
{
    int start2 = mid + 1;
    if (array[mid] <= array[start2])
        return;

    while (start <= mid and start2 <= end)
    {
        if (array[start] <= array[start2])
            start++;
        else
        {

            int value = array[start2];
            int index = start2;

            while (index != start)
            {
                array[index] = array[index - 1];
                index--;
            }

            array[start] = value;

            start++;
            mid++;
            start2++;
        }
    }
}

int nextGap(int gap)
{
    return gap <= 1 ? 0 : (int)ceil(gap / 2.0);
}

// TC: O(NlogN)
void mergeUsingShellSort(int arr[], int start, int end)
{
    int gap = end - start + 1;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {

        for (int i = start; i + gap <= end; i++)
        {
            int j = i + gap;
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

void mergeInPlace(int arr[], int start, int mid, int end)
{
    int mx = max(arr[mid], arr[end]) + 1;

    int i = start, j = mid + 1, k = start;
    while (i <= mid and j <= end and k <= end)
    {
        int e1 = arr[i] % mx;
        int e2 = arr[j] % mx;

        if (e1 <= e2)
        {
            arr[k] += (e1 * mx);
            i++;
            k++;
        }
        else
        {
            arr[k] += (e2 * mx);
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        int el = arr[i] % mx;
        arr[k] += (el * mx);
        i++;
        k++;
    }

    while (j <= end)
    {
        int el = arr[j] % mx;
        arr[k] += (el * mx);
        j++;
        k++;
    }

    for (int i = start; i <= end; i++)
        arr[i] = arr[i] / mx;
}

// TC: (O(logN))
void mergeSort(int arr[], int start, int end)
{

    if (start < end)
    {

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        mergeInPlace(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting:\n";
    printArray(arr, n);

    // Time Complexity: O(N^2 * log(N))
    mergeSort(arr, 0, n - 1);

    cout << "After sorting:\n";
    printArray(arr, n);

    // int arr1[] = {11, 12, 13, 5, 6, 7};
    // mergeInPlace(arr, 0, 2, 5);

    return 0;
}