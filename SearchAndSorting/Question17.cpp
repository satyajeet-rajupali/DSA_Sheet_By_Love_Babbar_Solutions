#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    // Code here
    int count = 0;
    int n = nums.size();
    map<int, int> m1;
    vector<int> v = nums;
    sort(v.begin(), v.end());

    for (int i = 0; i < nums.size(); i++)
        m1[nums[i]] = i;

    for (int i = 0; i < n; i++)
    {
        if (m1[v[i]] != i)
        {
            count++;
            int j = m1[v[i]];
            nums[j] = nums[i];
            m1[nums[i]] = j;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {2, 8, 5, 4};
    cout << "min swaps: " << minSwaps(nums) << "\n";
    return 0;
}