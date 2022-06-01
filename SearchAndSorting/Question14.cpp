#include <bits/stdc++.h>
using namespace std;

int findSubarray(vector<int> arr, int n)
{
    int count = 0;
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
                count++;
        }
    }

    return count;
}

void printMap(unordered_map<int, int> m)
{
    cout << "Elements in the map:\n";
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << "\n";
}

int findSubarrayOptimized(vector<int> arr, int n)
{
    int count = 0;
    int sum = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    cout << "Prefix Sum:\n";
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        count += m[sum];
        m[sum]++;
    }
    cout << "\n";
    printMap(m);
    return count;
}

int main()
{
    vector<int> v = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int ans = findSubarrayOptimized(v, v.size());
    cout << "Count: " << ans << "\n";
    return 0;
}