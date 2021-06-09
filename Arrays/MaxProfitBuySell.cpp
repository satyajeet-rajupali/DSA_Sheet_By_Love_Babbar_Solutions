#include <bits/stdc++.h>
using namespace std;

int maxProfitBuyOrSell(int *arr, int n)
{

    int *profit = new int[n];
    for (int i = 0; i < n; i++)
    {
        profit[i] = 0;
    }

    int max_price = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max_price)
        {
            max_price = arr[i];
        }

        profit[i] = max(profit[i + 1], max_price - arr[i]);
    }

    int min_price = arr[0];

    for (int i = 1; i < n; i++)
    {

        if (min_price > arr[i])
        {
            min_price = arr[i];
        }

        profit[i] = max(profit[i - 1], profit[i] + (arr[i] - min_price));
    }

    int res = profit[n - 1];

    delete[] profit;

    return res;
}

int main()
{
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfitBuyOrSell(price, n);
    return 0;
}
