#include <bits/stdc++.h>
using namespace std;

int pivotElement(vector<int> array)
{

    int start = 0;
    int end = array.size() - 1;
    int N = array.size();

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        int prev = (mid - 1 + N) % N;
        int next = (mid + 1) % N;

        if (array[start] <= array[end])
            return start;

        if ((array[mid] >= array[prev]) and (array[mid] <= array[next]))
            return mid;
        else if (array[start] <= array[mid])
            start = mid + 1;
        else if (array[mid] <= array[end])
            end = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> array = {11, 15, 16, 18, 2, 5, 6, 8};
    cout << "Pivot element: " << pivotElement(array) << "\n";
    return 0;
}