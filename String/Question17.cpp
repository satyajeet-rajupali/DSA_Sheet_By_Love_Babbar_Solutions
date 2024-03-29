#include <bits/stdc++.h>
using namespace std;

#define d 256

void search(char pat[], char txt[], int q)
{

    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    cout << "h: " << h << "\n";

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {

            bool flag = true;
            cout << "Found pattern: "
                 << "\n";
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
                cout << txt[i + j];
            }
            cout << "\n";
            if (flag)
                cout << i << " ";
            cout << "\n";

            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

void searchPattern(char pat[], char txt[], int q)
{
    int i, j;
    int M = strlen(pat);
    int N = strlen(txt);
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for (i = 0; i < N - M; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (j = 0; j < M; j++)
            {

                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << i <<" ";
            if (j == M)
            {
                cout << "Starting index is " << i << ".\n";
            }
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101;

    searchPattern(pat, txt, q);

    return 0;
}