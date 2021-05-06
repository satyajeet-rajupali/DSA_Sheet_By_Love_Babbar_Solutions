#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    auto comp = [](const vector<int> &m, const vector<int> &n) {
        return m[0] < n[0];
    };
    sort(intervals.begin(), intervals.end(), comp);


    cout << "Elements in vectors after sorting:\n";
    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals[i].size(); j++)
        {
            cout << intervals[i][j] << " ";
        }
        cout << endl;
    }

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
    // vector<vector<int>> ecp;
    // vector<int> rows;

    // if (intervals.size() == 1)
    // {
    //     return intervals;
    // }

    // int previousIntervalLeft = 0;
    // int previousIntervalRight = 0;
    // int nextIntervalLeft = 0;
    // int nextIntervalRight = 0;

    // for (int i = 1; i < intervals.size(); i++)
    // {
    //     for (int j = intervals[i].size() - 1; j < intervals[i].size(); j++)
    //     {

    //         previousIntervalLeft = intervals[i - 1][j - 1];
    //         previousIntervalRight = intervals[i - 1][j];

    //         nextIntervalLeft = intervals[i][j - 1];
    //         nextIntervalRight = intervals[i][j];

    //         if (previousIntervalRight <= nextIntervalLeft && (previousIntervalRight == nextIntervalRight || (previousIntervalRight >= nextIntervalLeft && previousIntervalRight == nextIntervalRight)))
    //         {
    //             rows.clear();
    //             rows.push_back(previousIntervalLeft);
    //             rows.push_back(previousIntervalRight);
    //             ecp.push_back(rows);
    //         }
    //         else if (nextIntervalLeft < previousIntervalLeft)
    //         {

    //             rows.clear();
    //             rows.push_back(nextIntervalLeft);
    //             rows.push_back(nextIntervalRight);
    //             ecp.push_back(rows);
    //         }
    //         else if (previousIntervalRight >= nextIntervalLeft)
    //         {

    //             rows.clear();
    //             rows.push_back(previousIntervalLeft);
    //             rows.push_back(nextIntervalRight);
    //             ecp.push_back(rows);
    //         }
    //         else
    //         {

    //             if (intervals.size() == 2)
    //             {

    //                 rows.clear();
    //                 rows.push_back(previousIntervalLeft);
    //                 rows.push_back(previousIntervalRight);
    //                 ecp.push_back(rows);

    //                 rows.clear();
    //                 rows.push_back(nextIntervalLeft);
    //                 rows.push_back(nextIntervalRight);
    //                 ecp.push_back(rows);
    //             }
    //             else
    //             {

    //                 rows.clear();
    //                 rows.push_back(nextIntervalLeft);
    //                 rows.push_back(nextIntervalRight);
    //                 ecp.push_back(rows);
    //             }
    //         }
    //     }
    // }

    // return ecp;
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