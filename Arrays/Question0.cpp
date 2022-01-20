
// Reversing the array
#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n)
{
    cout << "Elements in the array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void reverse(int arr[], int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
        swap(arr[i], arr[j]);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    reverse(arr, size);
    display(arr, size);
}