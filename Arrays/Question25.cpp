#include <bits/stdc++.h>
using namespace std;

int maxTwoBuySell(int arr[], int n)
{
    int FIRST_BUY = INT_MIN;
    int FIRST_SELL = 0;
    int SECOND_BUY = INT_MIN;
    int SECOND_SELL = 0;

    for (int i = 0; i < n; i++)
    {

        FIRST_BUY = max(FIRST_BUY, -arr[i]);
        FIRST_SELL = max(FIRST_SELL, FIRST_BUY + arr[i]);
        SECOND_BUY = max(SECOND_BUY, FIRST_SELL - arr[i]);
        SECOND_SELL = max(SECOND_SELL, SECOND_BUY + arr[i]);
    }

    return SECOND_SELL;
}

int main()
{

    int arr[] = {7, 6, 4, 3, 1};
    cout << "Max Profit: " << maxTwoBuySell(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}