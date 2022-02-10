#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum count of consecutive substrings str can be divided into such that all the substrings
// are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions
// then print -1.

int maxSubStr(string str, int n)
{
    int count0 = 0, count1 = 0, count = 0;

    for (int i = 0; str[i]; i++)
    {

        if (str[i] == '0')
            count0++;

        if (str[i] == '1')
            count1++;

        if (count1 == count0)
            count++;
    }

    if (count > 0)
    {
        return count;
    }

    return -1;
}

int main()
{
    string s = "000000000";
    cout << "Max Num of Substring: " << maxSubStr(s, s.length()) << "\n";
    return 0;
}