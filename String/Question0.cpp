#include <bits/stdc++.h>
using namespace std;

string reverseString(string str)
{
    int i = 0, j = str.length() - 1;

    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}

int main()
{
    cout << "Reverse String: " << reverseString("Satya") << "\n";
    return 0;
}