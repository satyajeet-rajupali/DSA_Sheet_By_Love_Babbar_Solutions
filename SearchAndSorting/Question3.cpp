#include <bits/stdc++.h>
using namespace std;

int countSqrt(int x)
{

    if (x == 0 or x == 1)
        return 0;

    int start = 1;
    int end = x / 2;
    int ans = 0;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        long long sqr = mid * mid;

        if (sqr == x)
            return ans;

        if (sqr <= x)
        {
            ans++;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int countSquares(int x)
{
    int i = 1;
    int res = 1;
    while (res < x)
    {
        i++;
        res = i * i;
    }

    return i - 1;
}

int main()
{
    int x = 3;
    cout << "Ans: " << countSquares(x) << "\n";
    return 0;
}