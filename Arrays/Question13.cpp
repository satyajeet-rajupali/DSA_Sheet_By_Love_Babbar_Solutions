#include <bits/stdc++.h>
using namespace std;

void mergeIntervals(vector<pair<int, int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int i = 1;
    vector<pair<int, int>>::iterator itr = intervals.begin();

    while (i < intervals.size())
    {
        itr = intervals.begin();
        if (intervals[i - 1].second >= intervals[i].first)
        {
            intervals[i - 1].second = intervals[i].second;
            advance(itr, i);
            intervals.erase(itr);
        }
        else
        {
            i++;
        }
    }

    cout << "Merged Intervals:\n";
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "[" << intervals[i].first << " " << intervals[i].second << "], ";
    }
    cout << "\n";
}

int main()
{

    vector<pair<int, int>> intervals = {
        make_pair(1, 3),
        make_pair(15, 18),
        make_pair(8, 10),
        make_pair(2, 6)};

    mergeIntervals(intervals);

    return 0;
}