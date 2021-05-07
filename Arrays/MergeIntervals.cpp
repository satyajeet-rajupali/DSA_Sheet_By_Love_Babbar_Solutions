#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    auto comp = [](const vector<int> &m, const vector<int> &n) {
        return m[0] < n[0];
    };
    sort(intervals.begin(), intervals.end(), comp);

    vector<int> now = intervals[0];
    vector<vector<int>> result;
    for (int i = 1; i < intervals.size(); i++)
    {
        const vector<int> &then = intervals[i];
        if (now[1] >= then[0])
        {
            now[1] = max(now[1], then[1]);
        }
        else
        {
            result.push_back(now);
            now = then;
        }
    }
    result.push_back(now);
    return result;
    
}

int main()
{

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    //vector<vector<int>> intervals = {{1, 4}, {5, 6}};

    vector<vector<int>> res = merge(intervals);

    cout << "Elements in vectors:\n";
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}