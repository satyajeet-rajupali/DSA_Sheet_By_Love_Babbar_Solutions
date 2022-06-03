#include <bits/stdc++.h>
using namespace std;

int isValid(int num, int n)
{
    int count = 0, f = 5;

    while (f <= num)
    {
        count += num / f;
        f = f * 5;
    }

    return (count >= n);
}

int findNum(int n)
{
    // complete the function here
    // if (n == 1)
    //     return 5;
    int start = 0;
    int end = 5 * n;
    int res;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (isValid(mid, n))
        {
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << "Number: " << findNum(n) << "\n";
    return 0;
}