#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n)
{

    cout << "Elements in arr:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int longestConsecutiveSequence(int arr[], int n)
{
    int count = 0;
    int count_so_far = 0;
    sort(arr, arr + n);
    display(arr, n);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == 1)
            count_so_far++;
        else if (arr[i] == arr[i - 1])
            continue;
        else
            count_so_far = 0;
        count = max(count, count_so_far);
    }
    return (count + 1);
}

int main()
{
    int arr[] = {6, 6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4, 2, 1, 3, 4, 5, 9, 6};
    cout << "Longest Consecutive Sequence: "
         << longestConsecutiveSequence(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}