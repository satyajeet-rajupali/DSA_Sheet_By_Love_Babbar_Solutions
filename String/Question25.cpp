#include <bits/stdc++.h>
using namespace std;

int decimalValue(char c)
{

    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
}

int romanToDecimal(string &str)
{
    int len = str.length();
    int sum = decimalValue(str[len-1]);
    for (int i = len-2; i >=0; i--)
    {
        if(decimalValue(str[i]) < decimalValue(str[i+1]))
            sum -= decimalValue(str[i]);
        else
            sum += decimalValue(str[i]);

    }
    return sum;
}

int main()
{
    string s = "MCMXCIV";
    cout << "Decimal Value: " << romanToDecimal(s)<<"\n";
    return 0;
}