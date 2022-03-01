#include <bits/stdc++.h>
using namespace std;

void solve(string arr[], string text)
{
    string output = "";

    for (int i = 0; text[i]; i++)
    {

        if (text[i] == ' ')
            output += "0";
        else
        {

            output += arr[text[i] - 'A'];
        }
    }

    cout << "Output: " << output << "\n";
}

int main()
{
    string arr[] = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"};
    string s = "GOLU";
    solve(arr, s);

    return 0;
}