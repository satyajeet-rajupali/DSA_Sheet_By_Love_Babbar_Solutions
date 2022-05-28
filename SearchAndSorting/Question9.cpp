#include <bits/stdc++.h>
using namespace std;

bool bs(int arr[], int size, int x)
{

    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == x)
            return true;
        else if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

bool findPair(int arr[], int size, int n)
{
    // code
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        int d = arr[i] + n;
        if (bs(arr, size, d))
            return true;
    }

    return false;
}

int main()
{
    int arr[] = {90, 70, 20, 80, 50};
    int n = 45;
    int size = sizeof(arr) / sizeof(arr[0]);

    findPair(arr, size, n) ? cout << "Present\n" : cout << "Not-Present\n";
    return 0;
}
