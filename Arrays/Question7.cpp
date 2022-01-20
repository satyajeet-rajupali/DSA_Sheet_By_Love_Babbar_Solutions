#include <bits/stdc++.h>
using namespace std;

int kadaneAlgorithm(int arr1[], int size)
{

    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + arr1[i];
        if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0)
            max_ending_here = 0;
    }

    return max_so_far;
}

int main()
{
    int arr[] = {-1, -2, -3, -4};
    cout << "Max Sum: " << kadaneAlgorithm(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
    return 0;
}