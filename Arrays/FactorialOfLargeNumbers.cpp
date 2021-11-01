#include <bits/stdc++.h>
using namespace std;


vector<int> multiply(int x, vector<int> vec);

// Recursive Function to calculate factorial.
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

// Iterative function to calculate factorial.
int factorialCalculator(int n)
{

    int res = 1;
    for (int i = n; i >= 1; i--)
    {
        res = res * i;
    }
    return res;
}


 

 
// This function finds factorial of large numbers
// and prints them
vector<int> factorial(int n)
{
    vector<int> result;
    result.push_back(1);
 
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++){
        result = multiply(x, result);

    }
     cout<<"Size of: "<<result.size()<<"\n";
 
    

    reverse(result.begin(), result.end());
    return result;    
}


 
// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function may value of res_size and returns the
// new value of res_size
vector<int> multiply(int x, vector<int> res)
{
    int carry = 0;  // Initialize carry
    
 
    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res.size(); i++)
    {
    
        int prod = res[i] * x + carry;
 
        // Store last digit of 'prod' in res[] 
        res[i] = prod % 10; 
 
        // Put rest in carry
        carry  = prod/10;   
    }
 
    // Put carry in res and increase result size
    while (carry)
    {
        res.push_back (carry%10);
        carry = carry/10;
    }
    return res;


}
 
int main()
{
    int x =897;
    vector<int> ans = factorial(x);
    cout<<"Answer:\n";
    for(auto it = ans.begin(); it!=ans.end(); it++){
        cout<<*it;
    }
    return 0;
}