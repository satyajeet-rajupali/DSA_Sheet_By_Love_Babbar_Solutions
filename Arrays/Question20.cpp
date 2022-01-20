#include <bits/stdc++.h>
using namespace std;

bool subarrayWithZero(int arr[], int size)
{

    unordered_multiset<int> um;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {

        sum += arr[i];
        if (sum == 0 || um.find(sum) != um.end())
            return true;
        um.insert(sum);
    }

    return false;
}

int main()
{

    int arr[] = {4, 2, -3, 1, 6};
    if (subarrayWithZero(arr, sizeof(arr) / sizeof(arr[0])))
        cout << "Sub-Array with zero exists.\n";
    else
        cout << "Sub-Array with zero doesn't exists.\n";

    return 0;
}