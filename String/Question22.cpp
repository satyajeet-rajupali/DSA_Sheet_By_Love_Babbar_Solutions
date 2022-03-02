#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

int internalSearch(string word, int row, int col, string words[],
                   int row_max, int col_max, int xx)
{
    int found = 0;
    if (row >= 0 and row <= row_max and col >= 0 and col <= col_max and word[xx] == words[row][col])
    {
        char match = word[xx];
        xx++;
        words[row][col] = 0;
        if (word[xx] == 0)
            found = 1;
        else
        {
            found += internalSearch(word, row, col + 1, words, row_max, col_max, xx);
            found += internalSearch(word, row, col - 1, words, row_max, col_max, xx);
            found += internalSearch(word, row + 1, col, words, row_max, col_max, xx);
            found += internalSearch(word, row - 1, col, words, row_max, col_max, xx);
        }
        words[row][col] = match;
    }
    return found;
}

int searchString(string word, int row,
                 int col, string words[],
                 int row_max, int col_max)
{
    int found = 0;

    for (int r = row; r < row_max; r++)
    {
        for (int c = col; c < col_max; c++)
        {
            found += internalSearch(word, r, c, words, row_max - 1, col_max - 1, 0);
        }
    }

    return found;
}

int main()
{
    string word = "MAGIC";
    string words[] = {"BBABBM",
                      "CBMBBA",
                      "IBABBG",
                      "GOZBBI",
                      "ABBBBC",
                      "MCIGAM"};

    cout << "Count: " << searchString(word, 0, 0, words, ARRAY_SIZE(words), words[0].size()) << "\n";

    return 0;
}