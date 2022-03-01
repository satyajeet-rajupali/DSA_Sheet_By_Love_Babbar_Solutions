#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int N, vector<int> arr)
{
    // code here

    int k, l;
    // If the size of the array is 0 or 1 then that array itself will be returned
    if (N <= 1)
    {
        return arr;
    }
    else
    {
        // Firstly, Find the elment which is smaller than its next element from back
        for (k = N - 2; k >= 0; k--)
        {
            if (arr[k] < arr[k + 1])
                break;
        }

        // If the whole array arr is in increasing order then the reverse operation will be peroformed
        // else this step will be performed
        if (k >= 0)
        {
            for (l = N - 1; l >= 0; l--)
            {
                if (arr[l] > arr[k])
                    break;
            }

            swap(arr[l], arr[k]);
            reverse(arr.begin() + k + 1, arr.end());
        }
        else
        {
            reverse(arr.begin(), arr.end());
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {3, 2, 1};
    vector<int> ans = nextPermutation(arr.size(), arr);

    cout << "Elements in array:\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << " ";
    cout << "\n";

    return 0;
}