#include <bits/stdc++.h>
using namespace std;

struct element
{

    int val;
    int index;
    int row;
    int arrsize;

    element() {}
    element(int val, int index, int row, int arrsize)
    {
        this->val = val;
        this->index = index;
        this->row = row;
        this->arrsize = arrsize;
    }
};

struct compare
{
    bool operator()(element a, element b)
    {
        return a.val > b.val;
    }
};

void smallestRange(vector<vector<int>> arr, int K)
{

    int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
    priority_queue<element, vector<element>, compare> minHeap;

    int k = K;
    int low, high;

    for (int i = 0; i < k; i++)
    {
        minHeap.emplace(element(arr[i][0], 0, i, arr[i].size()));
        mn = min(mn, arr[i][0]);
        mx = max(mx, arr[i][0]);
    }

    while (!minHeap.empty())
    {
        /* code */
        element temp = minHeap.top();
        minHeap.pop();

        int mayBeMinimum = temp.val;

        if (range > mx - mayBeMinimum)
        {

            mn = mayBeMinimum;
            range = mx - mn;
            low = mn;
            high = mx;
        }

        if (temp.index == temp.arrsize - 1)
            break;
        temp.index += 1;
        minHeap.emplace(element(arr[temp.row][temp.index],
                                temp.index,
                                temp.row,
                                arr[temp.row].size()));
        mx = max(mx, arr[temp.row][temp.index]);
    }

    // vector<int> v{low, high};
    // return v;
    cout << "low: " << low << "\n"
         << "high: " << high << "\n";
}

int main()
{
    vector<vector<int>> v = {{1, 3, 5, 7, 9},
                             {0, 2, 4, 6, 8},
                             {2, 3, 5, 7, 11}};
    smallestRange(v, 3);
    return 0;
}