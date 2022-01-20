#include <bits/stdc++.h>
using namespace std;

int maxProductArray(int arr[], int n)
{

    if (n == 1)
    {
        return arr[0];
    }

    int minVal = arr[0];
    int maxVal = arr[0];
    int max_so_far = arr[0];

    for (int i = 1; i < n; i++)
    {

        if (arr[i] < 0)
            swap(maxVal, minVal);

        minVal = min(arr[i], minVal * arr[i]);
        maxVal = max(arr[i], arr[i] * maxVal);

        max_so_far = max(max_so_far, maxVal);
    }

    return max_so_far;
}

int main()
{
    int arr[] = {6, -3, -10, 0, 2};
    cout << "Max Product: " << maxProductArray(arr, sizeof(arr) / sizeof(arr[0])) << "\n";

    return 0;
}