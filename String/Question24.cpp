#include <bits/stdc++.h>
using namespace std;

void display(unordered_map<char, int> &patternBadMatchContainer)
{
    cout << "\nValues in the map:\n";
    cout << "\tKEY\tELEMENT\n";
    for (auto itr = patternBadMatchContainer.begin(); itr != patternBadMatchContainer.end(); ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
}

void createBadCharacterMatchingArray(string pattern, unordered_map<char, int> &patternBadMatchContainer)
{
    int lengthOfPAttern = pattern.length();
    for (int i = 0; i < lengthOfPAttern; i++)
        patternBadMatchContainer[pattern[i]] = lengthOfPAttern - (i + 1);
    patternBadMatchContainer['*'] = lengthOfPAttern;
    patternBadMatchContainer[pattern[lengthOfPAttern - 1]] = lengthOfPAttern;
}

int BoyerMooreAlgorithm(string text, string pattern)
{
    unordered_map<char, int> patternBadMatchContainer;
    createBadCharacterMatchingArray(pattern, patternBadMatchContainer);
    display(patternBadMatchContainer);
    int lenOfPattern = pattern.length();
    int lenOfText = text.length();

    int pos(-1), i(lenOfPattern - 1);

    while (i < lenOfText)
    {
        if (pattern[lenOfPattern - 1] == text[i])
        {
            int k = i - 1, j;
            for (j = lenOfPattern - 2; j >= 0; j--, k--)
            {
                if (pattern[j] != text[k])
                    break;
            }
            // cout << "Value of j: " << j << "\n";
            if (j <= 0)
            {
                cout << "Pattern Matched: " << pattern[lenOfPattern - 1] << " == " << text[i] << " at " << i << "\n";

                pos = (i - lenOfPattern) + 1;
                cout << pos << " ";
                i = i + 1;

                // return pos;
            }
            else
            {
                if (patternBadMatchContainer.find(text[i]) != patternBadMatchContainer.end())
                    i = i + patternBadMatchContainer[text[i]];
                else
                    i = i + patternBadMatchContainer['*'];
            }
        }
        else
        {
            if (patternBadMatchContainer.find(text[i]) != patternBadMatchContainer.end())
                i = i + patternBadMatchContainer[text[i]];
            else
                i = i + patternBadMatchContainer['*'];
        }
        cout << "\ni: " << i << "\n";
    }
    return pos;
}

// GFG CODE
#define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's
// bad character heuristic
void badCharHeuristic(string str, int size,
                      int badchar[NO_OF_CHARS])
{
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence
    // of a character
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    /* Fill the bad character array by calling
    the preprocessing function badCharHeuristic()
    for given pattern */
    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is shift of the pattern with
               // respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0)
        {
            cout << "pattern occurs at shift = " << s << endl;

            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            s += max(1, j - badchar[txt[s + j]]);
    }
}

/* Driver code */

int main()
{
    string pattern = "COLLEGE";
    string text = "WELCOMETOSURANACOLLEGE";
    // cout << "Pattern is present at: " << BoyerMooreAlgorithm(text, pattern) << "\n";
    search(text, pattern);

    return 0;
}