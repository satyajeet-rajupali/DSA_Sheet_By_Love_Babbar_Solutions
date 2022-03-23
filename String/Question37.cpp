#include <bits/stdc++.h>
using namespace std;

void removeAdjacentCharacter(int pos, string &S)
{
    if (S[pos] == '\0')
        return;

    if (S[pos - 1] == S[pos])
    {
        S.erase(S.begin() + (pos - 1));
        removeAdjacentCharacter(pos, S);
    }
    else
        removeAdjacentCharacter(pos + 1, S);
}

string removeConsecutiveCharacter(string S)
{
    // code here.
    removeAdjacentCharacter(1, S);
    return S;
}

int main()
{
    string str = "aabaa";
    cout << "Ans: " << removeConsecutiveCharacter(str);

    return 0;
}