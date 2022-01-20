#include <bits/stdc++.h>
using namespace std;

void sortInAscendingOrder(int arr[], int size){
    
    int H[3] = {0};

    for (int i = 0; i < size; i++)
        H[arr[i]]++;

    int j = 0, k = 0;
    while (k < 3)
    {

        if (H[k] > 0)
        {
            arr[j++] = k;
            H[k]--;
        }
        else
            k++;
    }

    cout << "Elements in array:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    int arr[] = {0, 2, 1, 2, 0};
    sortInAscendingOrder(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}