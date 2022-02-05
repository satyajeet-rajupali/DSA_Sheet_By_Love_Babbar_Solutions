#include <bits/stdc++.h>
using namespace std;

void FNR(string str)
{
    queue<char> q;
    int charCount[26] = {0};

    // traverse whole stream
    for (int i = 0; str[i]; i++)
    {

        // push each character in queue
        q.push(str[i]);

        // increment the frequency count
        charCount[str[i] - 'a']++;

        // check for the non pepeating character
        while (!q.empty())
        {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else
            {
                cout << q.front();
                break;
            }
        }

        if (q.empty())
            cout << "#";
    }
    cout << endl;
}

int main()
{
    FNR("aabc");
    return 0;
}