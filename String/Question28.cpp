#include <bits/stdc++.h>
using namespace std;

string firstRepeatedWord(string str)
{

    istringstream iss(str);
    string token;

    set<string> ans;

    while (getline(iss, token, ' '))
    {
        if (ans.find(token) != ans.end())
            return token;
        ans.insert(token);
    }

    return "NoRepitions";
}

int main()
{
    string s = "Ravi had been saying that he had been there";
    cout << "Repeated String: " << firstRepeatedWord(s) << "\n";
    return 0;
}