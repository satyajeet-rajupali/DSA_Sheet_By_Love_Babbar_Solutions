#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str)
{
    int i = 0, j = str.length() - 1;

    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int main()
{
    string str = "aba";
    if (checkPalindrome(str))
    {
        cout << "Palindrome\n";
    }
    else
    {
        cout << "Not Palindrome\n";
    }

    return 0;
}