#include <bits/stdc++.h>
using namespace std;

int nrotation(vector<int> &array)
{

    int N = array.size();
    int start = 0;
    int end = N - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        int prev = (mid - 1 + N) % N;
        int next = (mid + 1) % N;

        if (array[start] <= array[end])
            return start;

        if (array[mid] < array[prev] and array[mid] < array[next])
            return mid;
        else if (array[start] < array[mid])
            start = mid + 1;
        else if (array[mid] < array[end])
            end = mid - 1;
    }

    return -1;
}

int bs(vector<int> &array, int target, int start, int end)
{

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (array[mid] == target)
            return mid;
        else if (array[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int search(vector<int> &nums, int target)
{
    int index = nrotation(nums);

    int ans = bs(nums, target, 0, index - 1);

    if (ans != -1)
        return ans;

    int ans1 = bs(nums, target, index, nums.size() - 1);

    if (ans1 != -1)
        return ans1;

    return -1;
}

// Highly Optimized code
int search1(vector<int> array, int target)
{

    int n = array.size();
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (array[mid] == target)
            return mid;

        else if (array[start] < array[mid])
        {
            if (target >= array[start] and target < array[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (target > array[mid] and target <= array[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "Ans: " << search1(nums, target) << "\n";
    return 0;
}