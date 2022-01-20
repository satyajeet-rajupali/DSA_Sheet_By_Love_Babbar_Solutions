#include <bits/stdc++.h>
using namespace std;

int maxSumSubArray(int arr[], int size)
{ // Kadane's Algorithm

    int max_ends_here = 0;
    int max_so_far = INT32_MIN;

    for (int i = 0; i < size; i++)
    {

        max_ends_here += arr[i];

        if (max_so_far < max_ends_here)
            max_so_far = max_ends_here;

        if (max_ends_here < 0)
            max_ends_here = 0;
    }

    return max_so_far;
}

int main()
{
    int arr[] = {1, 2, 3, -2, 5};

    cout << "Max Sum: " << maxSumSubArray(arr, sizeof(arr) / sizeof(arr[0])) << "\n";

    return 0;
}