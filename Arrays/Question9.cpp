#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;

    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    for (int i = 1; i < n; i++)
    {

        if (i == n - 1)
            return jump;

        maxReach = max(maxReach, i + arr[i]);
        step--;

        if (step == 0)
        {

            jump++;

            if (i >= maxReach)
            {
                return -1;
            }
            step = maxReach - i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    cout << "Min Jumps: "
         << minJumps(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}