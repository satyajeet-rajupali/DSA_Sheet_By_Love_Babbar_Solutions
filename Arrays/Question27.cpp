#include <bits/stdc++.h>
using namespace std;

void findThreeNumbers(int arr[], int n, int sum)
{
    int count = 0, rem_sum;
    sort(arr, arr + n);
    cout << "I am Working-1\n";
    for (int i = 0; i < n; i++)
    {
        cout << "I am Working-2\n";
        rem_sum = sum - arr[i];
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (arr[j] + arr[k] == rem_sum)
            {
                count++;
                cout << "Count: " << count << "\n";
                cout << "I am Working-3\n";
                j++;
            }
            else if (arr[j] + arr[k] > rem_sum)
                k--;
            else
                j++;
        }
        cout << "I am Working-4\n";
    }

    cout << "Total Count: " << count << "\n";
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    findThreeNumbers(arr, sizeof(arr) / sizeof(arr[0]), 13);
    return 0;
}