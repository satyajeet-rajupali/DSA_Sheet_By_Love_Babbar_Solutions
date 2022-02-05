#include <bits/stdc++.h>
using namespace std;

int minValue(string s, int k)
{
    // code here
    unordered_map<char, int> um;
    int i = 0;
    while (s[i] != '\0')
    {
        um[s[i]]++;
        i++;
    }

    priority_queue<int> pq;
    for (auto m : um)
        pq.emplace(m.second);

    while (k)
    {
        int data = pq.top();
        data--;
        pq.pop();
        pq.emplace(data);
        k--;
    }

    int sum = 0;

    while (!pq.empty())
    {
        int d = pq.top();
        sum += (d * d);
        pq.pop();
    }

    return sum;
}

int main()
{
    string s = "aabcbcbcabcc";
    int k = 3;
    cout << "Min Val: " << minValue(s, k) << "\n";
    return 0;
}