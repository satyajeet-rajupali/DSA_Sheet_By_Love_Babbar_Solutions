#include <bits/stdc++.h>
using namespace std;

void maximizing_profit(int arr[], int size)
{

    int max_diff_so_far = 0;
    int min_so_far = arr[0], buy_date, sell_date;
    buy_date = sell_date = -1;

    for (int i = 1; i < size; i++)
    {

        if (arr[i] < min_so_far)
        {
            min_so_far = arr[i];
            buy_date = i;
        }

        if (arr[i] - min_so_far > max_diff_so_far)
        {
            max_diff_so_far = arr[i] - min_so_far;
            sell_date = i;
        }
    }

    cout << "Max Profit: " << max_diff_so_far << "\n";

    if (buy_date != -1 && sell_date != -1)
        cout << "Bought on day " << (buy_date + 1)
             << " sold on day " << (sell_date + 1) << ".\n";
    else
        cout << "Didn't Buy any.";
}

int main()
{
    int arr[] = {7, 6, 4, 3, 1};
    maximizing_profit(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}