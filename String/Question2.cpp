#include <bits/stdc++.h>
using namespace std;

void printAllDuplicates(string str, int n)
{

    unordered_map<char, int> um;

    for (int i = 0; str[i]; i++)
        um[str[i]]++;

    cout << "Duplicate Elements:\n";
    for (auto m : um)
    {
        if (m.second > 1)
        {
            cout << m.first << ":" << m.second << "\n";
        }
    }
}

int main()
{
    string str = "satyajeet";
    printAllDuplicates(str, str.length());
    return 0;
}