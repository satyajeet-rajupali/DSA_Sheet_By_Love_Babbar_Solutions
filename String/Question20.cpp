#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{

    if (s.length() % 2 != 0)
        return -1;

    int open(0), close(0), i(0);

    while (s[i] != '\0')
    {
        if (s[i] == '{')
            open++;
        else
        {
            if (open > 0)
                open--;
            else
                close++;
        }
        i++;
    
    }

    return round(open / 2.0) + round(close / 2.0);
}

int main()
{
    string str = "{{}{{{}{{}}{{";
    cout << "Minimum reversals required: " << countRev(str) << "\n";
    return 0;
}