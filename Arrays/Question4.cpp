#include <bits/stdc++.h>
using namespace std;

void negativeAndPositive(int arr[], int size)
{
    int i = 0, j = (size - 1);

    while (i < j)
    {

        if (arr[i] < 0)
            i++;
        else if (arr[j] > 0)
            j--;
        else
        {
            swap(arr[i], arr[j]);
        }
    }

    cout << "Elements in array:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{

    int arr[] = {-12, 11, -13, -5,
                 6, -7, 5, -3, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    negativeAndPositive(arr, size);

    return 0;
}