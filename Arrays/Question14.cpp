#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &vec)
{

    next_permutation(vec.begin(), vec.end());

    cout << "Elements in vector:\n";
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

int main()
{
    vector<int> vec = {1, 1, 5};
    nextPermutation(vec);

    return 0;
}