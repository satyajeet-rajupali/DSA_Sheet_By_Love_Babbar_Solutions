#include <bits/stdc++.h>
using namespace std;

string solve(int arr[], int n)
{
    // code here
    string num1 = "", num2 = "";
    sort(arr, arr + n);

    for (int i = 0; i < n; i += 2)
        num1 += (arr[i] + '0');

    for (int i = 1; i < n; i += 2)
        num2 += (arr[i] + '0');

    int j = num1.length() - 1;
    int k = num2.length() - 1;

    int carry = 0;
    string ans = "";
    while (j >= 0 and k >= 0)
    {
        int sum = 0;
        sum += ((num1[j] - '0') + (num2[k] - '0') + carry);
        ans += to_string(sum % 10);
        carry = sum / 10;
        j--;
        k--;
    }

    while (j >= 0)
    {
        int sum = 0;
        sum += ((num1[j] - '0') + carry);
        ans += to_string(sum % 10);
        carry = sum / 10;
        j--;
        k--;
    }

    while (k >= 0)
    {
        int sum = 0;
        sum += ((num2[k] - '0') + carry);
        ans += to_string(sum % 10);
        carry = sum / 10;
        k--;
    }

    if (carry)
        ans += to_string(carry);

    while (!ans.empty() and ans.back() == '0')
        ans.pop_back();

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int arr[] = {1, 1, 5, 2, 7, 6, 1,
                 4, 2, 3, 2, 2, 1, 6,
                 8, 5, 7, 6, 1, 8, 9,
                 2, 7, 9, 5, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Ans: " << solve(arr, n) << "\n";
    return 0;
}