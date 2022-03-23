#include <bits/stdc++.h>
using namespace std;

// Minimum operations required to convert a String A to String B
int minimumOperations(string A, string B)
{
    int validation_array[256];
    int mA = A.size(), mB = B.size();

    if (mA != mB)
        return -1;

    memset(validation_array, 0, sizeof(validation_array));

    // Checks whether both of the strings are Anagrams or not
    for (int i = 0; i < mA; i++)
        validation_array[(int)A[i]]++;
    for (int j = 0; j < mB; j++)
        validation_array[(int)B[j]]--;
    for (int i = 0; i < 256; i++)
        if (validation_array[i])
            return -1;

    int res = 0;

    for (int i = A.size() - 1, j = B.size() - 1; i >= 0;)
    {
        while (i >= 0 and A[i] != B[j])
        {
            i--;
            res++;
        }

        if (i >= 0)
        {
            i--;
            j--;
        }
    }

    return res;
}

int main()
{
    string A = "EACBD", B = "EABCD";
    cout << "Minimum Operations: " << minimumOperations(A, B) << "\n";
    return 0;
}