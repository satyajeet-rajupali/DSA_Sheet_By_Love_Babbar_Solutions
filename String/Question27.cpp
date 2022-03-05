#include <bits/stdc++.h>
using namespace std;

int minFlips(string str)
{
    int len = str.length();
    int c1(0), c2(0);

    for (int i = 0; i < len; i++)
    {

        if (i % 2 == 0)
        {

            if (str[i] == '1')
                c1++;
            if (str[i] == '0')
                c2++;
        }
        else
        {

            if (str[i] == '1')
                c2++;
            if (str[i] == '0')
                c1++;
        }
    }

    return min(c1, c2);
}

int main()
{
    string s = "0001010111";
    cout << "Min Flips: " << minFlips(s) << "\n";
    return 0;
}