#include <bits/stdc++.h>
using namespace std;

void solve(int m, vector<vector<string>> input, string str)
{
    if (m == input.size())
    {
        cout << str << "\n";
        return;
    }
    for (int i = 0; i < input[m].size(); i++)
        solve(m + 1, input, str + input[m][i] + " ");
}

int main()
{
    vector<vector<string>> input = {{"you", "we"},
                                    {"have", "are"},
                                    {"sleep", "eat", "drink"}};
    solve(0, input, "");
    // cout << "Input Size: " << input.size() << "\n";
    return 0;
}