#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int size)
{

    cout << "Elements in array:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void alternatePositiveNegative(int arr[], int size)
{

    int i = 1, j = size - 1;
    int firstPositive = 0;
    display(arr, size);
    sort(arr, arr + size);
    display(arr, size);

    while (arr[firstPositive] < 0)
        firstPositive++;
    cout << "FP: " << firstPositive << "\n";

    if (firstPositive > 1)
    {
        while (i < size && j >= firstPositive && arr[i] < 0)
        {
            swap(arr[i], arr[firstPositive]);
            i += 2;
            firstPositive++;
        }
    }
    display(arr, size);
}

int main()
{

    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    alternatePositiveNegative(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}