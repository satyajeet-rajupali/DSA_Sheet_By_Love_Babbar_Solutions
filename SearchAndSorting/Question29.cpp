#include <bits/stdc++.h>
using namespace std;

int MaxElement(int array[], int N)
{
    int start = 0;
    int end = N - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (mid > 0 and mid < N - 1)
        {

            if (array[mid] > array[mid - 1] and array[mid] > array[mid + 1])
                return array[mid];
            else if (array[mid] < array[mid - 1])
                end = mid - 1;
            else if (array[mid] < array[mid + 1])
                start = mid + 1;
        }
        else if (mid == 0)
        {
            if (array[0] > array[1])
                return array[0];
            return array[1];
        }
        else if (mid == N - 1)
        {
            if (array[N - 2] > array[N - 1])
                return array[N - 2];
            return array[N - 1];
        }
    }
    return -1;
}

bool isValid(int pages[], int mx, int N, int NS)
{
    int students = 1;
    int pageAlloc = 0;
    for (int i = 0; i < N; i++)
    {
        pageAlloc += pages[i];

        if (pageAlloc > mx)
        {
            students++;
            pageAlloc = pages[i];
        }

        if (students > NS)
            return false;
    }

    return true;
}

int findPages(int pages[], int N, int NS)
{
    // code here
    int start = MaxElement(pages, N);
    int end = accumulate(pages, pages + N, 0);
    int ans;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (isValid(pages, mid, N, NS))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{
    int arr[] = {15, 17, 20};
    int M = 2;
    int N = sizeof(arr) / sizeof(arr[0]);
    int ans = findPages(arr, N, M);
    cout << "Pages Allocated: " << ans << "\n";
    return 0;
}