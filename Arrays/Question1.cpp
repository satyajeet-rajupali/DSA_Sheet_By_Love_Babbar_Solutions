#include <bits/stdc++.h>
using namespace std;

// Min and maximum of array
struct MinandMax
{
    int min, max;
};

struct MinandMax soltuion(int arr[], int n)
{

    struct MinandMax mimx;
    mimx.min = INT32_MAX;
    mimx.max = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mimx.min)
            mimx.min = arr[i];
        else if (arr[i] > mimx.max)
            mimx.max = arr[i];
    }

    return mimx;
}

int main()
{
    struct MinandMax mimx;
    int arr[] = {1, 2, 3, 4, 5};

    mimx = soltuion(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "Max: " << mimx.max << "\n"
         << "Min: " << mimx.min << "\n";
    return 0;
}
