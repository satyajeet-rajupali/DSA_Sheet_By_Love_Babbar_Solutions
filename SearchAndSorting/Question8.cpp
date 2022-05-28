#include <bits/stdc++.h>
using namespace std;

// It will work only in case of sorted array
int searchFirstOccurenceOfElementWithKDifference(int arr[], int n, int k, int x)
{
    int start = 0;

    int end = n - 1;
    int pos = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] == x)
        {
            pos = mid;
            end = mid - 1;
        }
        else if (arr[mid] > x)
            end = mid - 1;
        else if (arr[mid] < x)
            start = mid + 1;
    }

    return pos;
}

int searchFirstOccurenceOfElementWithKDifference1(int arr[], int n, int k, int x)
{
    int i = 0;

    while (i < n)
    {
        if (arr[i] == x)
            return i;

        i += max(1, abs(x - arr[i]) / k);
    }

    return -1;
}

int main()
{
    int ar[] = {4, 5, 6, 7, 6};
    int k = 1;
    int x = 6;

    cout << "First Occurrence: " << searchFirstOccurenceOfElementWithKDifference1(ar, 6, k, x) << "\n";

    return 0;
}