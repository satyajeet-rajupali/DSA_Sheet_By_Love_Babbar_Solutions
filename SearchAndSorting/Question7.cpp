#include <bits/stdc++.h>
using namespace std;

// Moore Voting Algorithm
int searchCandidate(int a[], int size)
{
    int count = 0;
    int candidate = 0;

    for (int i = 0; i < size; i++)
    {
        if (count == 0)
            candidate = a[i];
        if (a[i] == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}

bool isMajority(int a[], int size, int candidate)
{

    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == candidate)
            count++;
    }

    if (count > size / 2)
        return true;
    return false;
}

int majorityElement(int a[], int size)
{
    int candidate = searchCandidate(a, size);
    return isMajority(a, size, candidate) ? candidate : -1;
}

int main()
{
    int arr[] = {3, 1, 3, 3, 2};
    cout << "Ans: " << majorityElement(arr, sizeof(arr) / sizeof(arr[0])) << "\n";

    return 0;
}