#include <bits/stdc++.h>
using namespace std;

int minMergeCount(vector<int> &vec)
{

    int i = 0, j = vec.size() - 1, ans = 0;

    while (i <= j)
    {

        if (vec[i] == vec[j])
        {
            i++;
            j--;
        }
        else if (vec[i] > vec[j])
        {
            j--;
            vec[j] += vec[j + 1];
            ans++;
        }
        else
        {
            i++;
            vec[i] += vec[i - 1];
            ans++;
        }
    }

    return ans;
}

int main()
{
    vector<int> vec = {1, 4, 5, 9, 1};
    cout << "Min Number of merge: " << minMergeCount(vec) << "\n";

    return 0;
}