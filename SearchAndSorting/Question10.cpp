#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> ans)
{
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
}

bool binarySearch(vector<int> &v, int K, int start, int end, int &idx)
{
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (v[mid] == K)
        {
            idx = mid;
            return true;
        }
        else if (v[mid] < K)
            start = mid + 1;
        else if (v[mid] > K)
            end = mid - 1;
    }

    return false;
}

void findPairWithK(vector<int> v, int N, int K)
{

    sort(v.begin(), v.end());

    for (int i = 0; i < N - 1; i++)
    {
        int d = K - v[i];
        int idx = -1;
        if (binarySearch(v, d, i + 1, N - 1, idx))
        {
            if (idx != -1)
                cout << v[i] << ", " << v[idx] << "\n";
        }
    }
}

vector<vector<int>> fourSum(vector<int> &arr, int K)
{
    // Your code goes here
    vector<vector<int>> ans;
    set<vector<int>> sub_ans;
    // vector<int> sub_ans;
    sort(arr.begin(), arr.end());
    int res = 0;
    int n = arr.size();
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int sum = arr[i] + arr[j];
            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                if (sum + arr[k] + arr[l] == K)
                {
                    sub_ans.insert({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                }
                else if (sum + arr[k] + arr[l] < K)
                    k++;
                else
                    l--;
            }
        }
    }

    for (auto it = sub_ans.begin(); it != sub_ans.end(); it++)
        ans.push_back(*it);

    // cout << "Elements:\n";
    // cout << "Size of ans: " << ans.size() << "\n";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     printVector(ans[i]);
    // }
    return ans;
}

int main()
{
    vector<int> v = {0, 0, 2, 1, 1};
    int k = 3;
    // fourSum(v, k);
    findPairWithK(v, v.size(), k);
    return 0;
}