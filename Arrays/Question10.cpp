#include <bits/stdc++.h>
using namespace std;

int getDuplicateNumber(int arr[], int n)
{

    int dupNum = ((n - 1) * n) / 2;

    for (int i = 0; i < n; i++)
        dupNum -= arr[i];

    return abs(dupNum);
}

int main()
{

    int arr[] = {3, 1, 3, 4, 2};
    cout << "Duplicate Number: "
         << getDuplicateNumber(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
    return 0;
}