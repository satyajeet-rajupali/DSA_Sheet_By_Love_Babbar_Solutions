#include <bits/stdc++.h>
using namespace std;

void printArray(long long arr[], int n)
{
    cout << "Elements in the array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    // sort(arr, arr + n);
    long long count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] >= sum)
                k--;
            else
            {
                count += (k - j);
                j++;
            }
        }
    }
    return count;
}

int main()
{
    long long arr[] = {5, 1, 3, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long sum = 12;
    cout << "Count: " << countTriplets(arr, n, sum) << "\n";
    return 0;
}