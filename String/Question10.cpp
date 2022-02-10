#include <bits/stdc++.h>
using namespace std;

void permute(string A, int l, int r)
{

    if (l == r)
    {
        cout << A << "\n";
        return;
    }
    else
    {
        // cout << "Loop Starts:\n";
        for (int i = l; i <= r; i++)
        {
            // cout << "For i: " << i << "\n";
            // cout << "Performing swap before recursion call:\n";
            // cout << "Swapping " << A[l] << " and " << A[i] << "\n";
            swap(A[l], A[i]);
            // cout << "After Swap bfrc " << A << "\n";
            permute(A, l + 1, r);
            // cout << "Performing swap After recursion call:\n";
            // cout << "Swapping " << A[l] << " and " << A[i] << "\n";
            swap(A[l], A[i]);
            // cout << "After Swap afrc " << A << "\n";
        }
    }
}

void permutationOfstrings(string s, string answer)
{

    if (s.length() == 0)
    {
        cout << answer << "\n";
        return;
    }
    else
    {

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            string left_string = s.substr(0, i);
            string right_string = s.substr(i + 1);
            string rest = left_string + right_string;
            permutationOfstrings(rest, answer + ch);
        }
    }
}

void permute(string A, int l, int r, vector<string> &ans)
{

    if (l == r)
    {
        cout << A << "\n";
        ans.push_back(A);
        return;
    }
    else
    {
        // cout << "Loop Starts:\n";
        for (int i = l; i <= r; i++)
        {
            // cout << "For i: " << i << "\n";
            // cout << "Performing swap before recursion call:\n";
            // cout << "Swapping " << A[l] << " and " << A[i] << "\n";
            swap(A[l], A[i]);
            // cout << "After Swap bfrc " << A << "\n";
            permute(A, l + 1, r, ans);
            // cout << "Performing swap After recursion call:\n";
            // cout << "Swapping " << A[l] << " and " << A[i] << "\n";
            swap(A[l], A[i]);
            // cout << "After Swap afrc " << A << "\n";
        }
    }
}

vector<string> find_permutation(string S)
{
    // Code here there
    vector<string> ans;
    permute(S, 0, S.length() - 1, ans);
    return ans;
}

int main()
{
    string s = "ABC";
    // permute(s, 0, s.length() - 1);

    // cout << s.substr(0, 1) << "\n";
    // cout << s.substr(1, 2) << "\n";

    // permutationOfstrings(s, "");

    vector<string> ans = find_permutation(s);
    sort(ans.begin(), ans.end());
    cout << "Answer:\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << "\n";

    return 0;
}