#include <bits/stdc++.h>
using namespace std;

// Using Array Preprocessing
int TrappingRainWater(int arr[], int n)
{
    int water = 0;
    int left[n], right[n];
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];

    return water;
}

// Space Optimized Solution
int TrappedRainWater(int arr[], int n)
{

    int water = 0, i = 0, j = n - 1, rm = 0, lm = 0;

    while (i <= j)
    {
        if (arr[i] < arr[j])
        {
            if (arr[i] > lm)
                lm = arr[i];
            else
                water += lm - arr[i];
            i++;
        }
        else
        {
            if (arr[j] > rm)
                rm = arr[j];
            else
                water += rm - arr[j];
            j--;
        }
    }

    return water;
}

int main()
{

    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Water Collected: " << TrappingRainWater(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "\nWater Collected(Space Optimized): " << TrappedRainWater(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}