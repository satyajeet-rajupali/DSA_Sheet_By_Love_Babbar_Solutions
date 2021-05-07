#include <bits/stdc++.h>
using namespace std;

// Input:
// N = 4, K = 6
// arr[] = {1, 5, 7, 1}
// Output: 2
// Explanation:
// arr[0] + arr[1] = 1 + 5 = 6
// and arr[1] + arr[3] = 5 + 1 = 6.

int getPairsCount(int arr[], int n, int k)
{
    // code here
    unordered_map<int, int> map;
    for(int i=0; i<n; i++){
        map[arr[i]]++;
    }
    int count = 0;

    for(int i=0; i<n; i++){
        count = count + map[k-arr[i]];

        if(k - arr[i] == arr[i])
            count--;
    }

    return count/2;
}

int main()
{
    //int arr[] = {1, 5, 7, 1};
    int arr[] = {1, 1, 1, 1};
    cout<<"Pairs Count: "<<getPairsCount(arr,sizeof(arr)/sizeof(arr[0]),2);
    return 0;
}