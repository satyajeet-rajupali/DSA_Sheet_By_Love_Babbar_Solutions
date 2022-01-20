#include <bits/stdc++.h>
using namespace std;

void pair_with_sum_k(int arr[], int size, int sum)
{

    unordered_map<int, int> um;

    for (int i = 0; i < size; i++)
        um[arr[i]]++;

    int tc = 0;

    for (int i = 0; i < size; i++)
    {

        tc += um[sum - arr[i]];

        if (sum - arr[i] == arr[i])
            tc--;
    }

    cout << "Total Pairs that exists: " << (tc / 2) << "\n";
}

int main()
{
    int arr[] = {1, 1, 1, 1}, sum = 2;
    pair_with_sum_k(arr, sizeof(arr) / sizeof(arr[0]), sum);

    return 0;
}