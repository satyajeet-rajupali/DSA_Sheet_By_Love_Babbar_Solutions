#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n)
{
    // code here
    int *ans;
    int i = 0;
    while (i < n)
    {
        if (arr[i] == arr[arr[i] - 1])
            i++;
        else
        {
            if (arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
            else
                i++;
        }
    }

    for (int i = 0; i < n; i++)
        if (arr[i] != i + 1)
        {
            ans = new int[2];
            // Repeating Value
            ans[0] = arr[i];

            // Missing Value
            ans[1] = i + 1;
        }

    return ans;
}

int *findTwoElement1(int *arr, int n)
{
    // code here
    int *ans;
    long long sum = (n * (n + 1)) / 2;
    long long sum_sq = (n * (n + 1) * (2 * n + 1)) / 6;

    for (int i = 0; i < n; i++)
    {
        sum = sum - arr[i];
        sum_sq = sum_sq - (arr[i] * arr[i]);
    }
    ans = new int[2];
    ans[1] = (sum + sum_sq / sum) / 2;
    ans[0] = ans[1] - sum;
    return ans;
}

int main()
{
    int arr[] = {1, 3, 3};
    int *ans1 = findTwoElement1(arr, 3);

    cout << "Repeating: " << ans1[0] << ", Missing: " << ans1[1] << "\n";
    return 0;
}