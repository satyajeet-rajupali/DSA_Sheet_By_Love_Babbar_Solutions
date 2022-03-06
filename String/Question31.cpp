// C++ program to generate all possible
// valid IP addresses from given string
#include <bits/stdc++.h>
using namespace std;

void display(vector<string> &ans)
{
    cout << "Answer:\n";
    cout << "size: " << ans.size() << "\n";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << "\n";
}

// Function checks whether IP digits
// are valid or not.
int is_valid(string ip)
{
    // Splitting by "."
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            ips.push_back(ex);
            ex = "";
        }
        else
        {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);

    // Checking for the corner cases
    // cout << ip << endl;
    for (int i = 0; i < ips.size(); i++)
    {
        // cout << ips[i] <<endl;
        if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) == 0)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')
            return 0;
    }
    return 1;
}

// Function converts string to IP address
void convert(string ip)
{
    int l = ip.length();

    // Check for string size
    if (l > 12 || l < 4)
    {
        cout << "Not Valid IP Address";
    }

    string check = ip;
    vector<string> ans;

    // Generating different combinations.
    for (int i = 1; i < l - 2; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            for (int k = j + 1; k < l; k++)
            {
                // cout << "i: " << i << " j: " << j << " k: " << k << "\n";
                check = check.substr(0, k) + "." + check.substr(k);
                // cout << "Check:1 " << check << "\n";
                check = check.substr(0, j) + "." + check.substr(j);
                // cout << "Check:2 " << check << "\n";
                check = check.substr(0, i) + "." + check.substr(i);
                // cout << "Check:2 " << check << "\n";

                // cout<< check <<endl;
                // Check for the validity of combination
                if (is_valid(check))
                {
                    ans.push_back(check);
                    std::cout << check << '\n';
                }
                check = ip;
            }
        }
    }
}

void snapShot(vector<string> &allIpAdresses, string s, int builderIndex, int path[], int segment)
{

    if (segment == 4 and builderIndex == s.length())
    {
        allIpAdresses.push_back(to_string(path[0]) + "." + to_string(path[1]) + "." + to_string(path[2]) + "." + to_string(path[3]));
        return;
    }
    else if (segment == 4 or builderIndex == s.length())
    {
        return;
    }

    for (int len = 1; len <= 3 and (builderIndex + len) <= s.length(); len++)
    {
        string snapshot = s.substr(builderIndex, builderIndex + len);
        int value = stoi(snapshot);
        if ((value > 255 or len >= 2) and s[builderIndex] == '0')
        {
            break;
        }
        path[segment] = value;
        snapShot(allIpAdresses, s, builderIndex + len, path, segment + 1);
        path[segment] = -1;
    }
}

// Driver code
int main()
{
    string A = "25525511135";
    string B = "25505011535";
    int path[4];
    vector<string> ans;
    // convert(A);
    snapShot(ans, A, 0, path, 0);
    display(ans);
    // convert(B);

    return 0;
}
