#include <bits/stdc++.h>
using namespace std;

bool validShuffle(string s1, string s2, string result)
{

    if (s1.length() + s2.length() != result.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(result.begin(), result.end());

    int i = 0, j = 0, k = 0;

    while (result[k] != '\0')
    {
        if (i < s1.length() and s1[i] == result[k])
            i++;
        else if (j < s2.length() and s2[j] == result[k])
            j++;
        else
            return false;
        k++;
    }

    if (i < s1.length() or i < s2.length())
    {
        return false;
    }

    return true;
}

void checkValidity(string s1, string s2, string result)
{
    if (validShuffle(s1, s2, result))
        cout << "Valid Shuffle\n";
    else
        cout << "Invalid Shuffle\n";
}


int main()
{

    checkValidity("XY", "12", "1YX2");
    checkValidity("XY", "12", "Y1X2");
    checkValidity("XY", "12", "Y21XX");

    return 0;
}