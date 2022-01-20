#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &hash)
{
    cout << "Elements in the vector:\n";
    for (auto it = hash.begin(); it != hash.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

vector<int> majorityElement(vector<int> &nums)
{

    vector<int> ans;
    int th = nums.size() / 3;
    map<int, int> hash;

    for (int i = 0; i < nums.size(); i++)
        hash[nums[i]]++;

    for (auto it = hash.begin(); it != hash.end(); it++)
    {
        if (it->second > th)
            ans.push_back(it->first);
    }

    // cout << "Elements in the map:\n";
    // for (auto it = hash.begin(); it != hash.end(); it++)
    //     cout << it->first << " " << it->second << "\n";

    return ans;
}

int main()
{
    vector<int> vec = {1, 2};
    vector<int> ans = majorityElement(vec);

    if (ans.size() > 0)
        display(ans);
    else
        cout << "No such value exists\n";

    return 0;
}