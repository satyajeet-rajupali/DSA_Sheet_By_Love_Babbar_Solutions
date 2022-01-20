#include <bits/stdc++.h>
using namespace std;

void rotateBy1(int *arr, int size, int rn)
{
    int temp = 0;

    if (rn == -1)
    {
        temp = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
    }
    else
    {
        temp = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }

    cout << "Elements in the array:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    rotateBy1(arr, sizeof(arr) / sizeof(arr[0]), 1);
    return 0;
}