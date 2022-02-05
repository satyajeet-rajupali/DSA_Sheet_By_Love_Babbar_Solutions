#include <bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2)
{

    if (s1.length() != s2.length())
        return false;

    string temp = s1 + s2;
    return (temp.find(s2) != string::npos);
}

int main()
{
    string s1="AACD", s2="ACDA";

    if (areRotations(s1, s2))
    {
        cout << "Both string are rotations of each other\n";
    }
    else
    {
        cout << "Both string aren't rotations of each other\n";
    }
    return 0;
}