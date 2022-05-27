#include <bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n, int x)
{

    int start = 0;
    int end = n - 1;
    int pos = -1;
    vector<int> ans;

    while (start <= end)
    {

        int mid = start + ((end - start) / 2);

        if (arr[mid] == x)
        {
            pos = mid;
            end = mid - 1;
        }
        else if (arr[mid] > x)
            end = mid - 1;
        else if (arr[mid] < x)
            start = mid + 1;
    }
   
    ans.push_back(pos);

    start = 0;
    end = n - 1;
    pos = -1;

    while (start <= end)
    {

        int mid = start + ((end - start) / 2);

        if (arr[mid] == x)
        {
            pos = mid;
            start = mid + 1;
        }
        else if (arr[mid] > x)
            end = mid - 1;
        else if (arr[mid] < x)
            start = mid + 1;
    }

    
    ans.push_back(pos);


    return ans;
}

int main()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    vector<int> ans = find(arr, n, x);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}