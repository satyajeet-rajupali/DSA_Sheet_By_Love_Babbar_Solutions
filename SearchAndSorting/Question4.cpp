#include <bits/stdc++.h>
using namespace std;

// Simple Linear search method
pair<int, int> getMinMax(vector<int> array, int n)
{
    if (n == 1)
        return make_pair(array[0], array[0]);

    int min, max;

    if (array[0] > array[1])
        min = array[1], max = array[0];
    else
        min = array[0], max = array[1];

    for (int i = 2; i < n; i++)
    {
        if (array[i] < min)
            min = array[i];
        else if (array[i] > max)
            max = array[i];
    }

    return make_pair(min, max);
}

// Tournament Method
// pair<min element, max element>
pair<int, int> getMinMax(vector<int> array, int low, int high)
{
    pair<int, int> minMax, mml, mmr;
    int mid;

    if (low == high)
    {
        minMax.first = array[low];
        minMax.second = array[low];
        return minMax;
    }

    if (low == high + 1)
    {
        if (array[low] < array[high])
        {
            minMax.first = array[low];
            minMax.second = array[high];
        }
        else
        {
            minMax.first = array[high];
            minMax.second = array[low];
        }

        return minMax;
    }

    mid = low + ((high - low) / 2);
    mml = getMinMax(array, low, mid);
    mmr = getMinMax(array, mid + 1, high);

    if (mml.first < mmr.first)
        minMax.first = mml.first;
    else
        minMax.first = mmr.first;

    if (mml.second > mmr.second)
        minMax.second = mml.second;
    else
        minMax.second = mmr.second;

    return minMax;
}

// Compare in pairs
// pair<min element, max element>
pair<int, int> getMinMax(vector<int> array)
{
    int n = array.size();
    pair<int, int> minMax;
    int i = 0;

    if (n % 2 == 0)
    {
        if (array[0] < array[1])
        {
            minMax.first = array[0];
            minMax.second = array[1];
        }
        else
        {
            minMax.first = array[1];
            minMax.second = array[0];
        }
        i += 2;
    }
    else
    {
        minMax.first = array[0];
        minMax.second = array[0];
        i = 1;
    }

    while (i < n - 1)
    {
        if (array[i] < array[i + 1])
        {
            if (array[i] < minMax.first)
                minMax.first = array[i];

            if (array[i + 1] > minMax.second)
                minMax.second = array[i + 1];
        }
        else
        {
            if (array[i + 1] < minMax.first)
                minMax.first = array[i + 1];

            if (array[i] > minMax.second)
                minMax.second = array[i];
        }
        i++;
    }

    return minMax;
}

int main()
{
    vector<int> v = {1000, 11, 445, 1, 330, 3000};

    pair<int, int> ans = getMinMax(v);
    cout << "Min: " << ans.first << ", Max: " << ans.second << "\n";

    return 0;
}