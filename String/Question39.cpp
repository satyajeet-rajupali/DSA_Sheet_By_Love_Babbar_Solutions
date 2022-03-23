#include <bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int n, string str)
{
    int ans(0), count(0);
    unordered_map<char, int> record;
    unordered_map<char, int> record1;

    for (int i = 0; str[i]; i++)
    {
        if (record.find(str[i]) == record.end() && count < n)
        {
            record[str[i]] = 1;
            count++;
        }
        else if (record.find(str[i]) != record.end())
        {
            record.erase(str[i]);
            count--;
        }
        else if (record.find(str[i]) == record.end() && count == n)
        {
            if (record1.find(str[i]) == record1.end())
            {
                ans++;
                record1[str[i]] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    int n = 3;
    string seq = "ABBAJJKZKZ";
    cout << "Answer: " << runCustomerSimulation(n, seq) << "\n";
    return 0;
}