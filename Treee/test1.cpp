#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)

void display(vector<int> subset)
{
    cout << "{";
    for (auto it = subset.begin(); it != subset.end(); it++)
    {
        cout << *it << ",";
    }
    cout << "}\n";
}

void search(int k, vi &v, int n)
{
    if (k == n + 1)
    {
        display(v);
    }
    else
    {
        v.PB(k);
        search(k + 1, v, n);
        v.POB();
        search(k + 1, v, n);
    }
}


int main()
{

    // These lines will make the input and output more efficient.
    ios::sync_with_stdio(0);
    cin.tie(0);

    // string s1, s2, s3;
    // // This code only allows to read text with spaces.
    // cin>>s1>>s2>>s3;
    // cout<<s1<<"\n"<<s2<<"\n"<<s3<<"\n";

    // This code allows the program to read text with spaces.
    // string line;
    // getline(cin, line);
    // cout<<line<<"\n";

    // This loop is useful when the amount of data is unknown.
    // int a, b;
    // while (cin >> a){
    // }

    // int a = 1;
    // long long num = 123456789123456789LL;

    // long long m = 10e8 + 7;

    // long long n;
    // cin>>n;

    // long long x = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     x = (x * i) % m;
    // }
    // cout << x << "\n";
    // double e = 1e-9;

    // double x = 0.3 * 3 + 0.1;
    // printf("%.20f\n", x);
    // double y = 1.0;

    // if (abs(y - x) < e)
    // {
    //     cout << "Equal";
    // }
    // printf("Value of e = %.9f\n", e);

    // Shortening of code

    // vi vec;
    // vec.PB(10);
    // vec.PB(20);
    // vec.PB(30);

    // vp v1;
    // v1.PB(MP(1, 10));
    // v1.PB(MP(2, 20));
    // v1.PB(MP(3, 30));

    // cout << "Elements in vector vec:\n";
    // REP(i, 0, vec.size())
    // {
    //     cout << vec[i] << " ";
    // }
    // cout << "\n";

    // cout << "Elements in vector v1:\n";
    // REP(i, 0, v1.size())
    // {
    //     cout << v1[i].F << " " << v1[i].S << "\n";
    // }
    // cout << "\n";

    // vi subset;
    // int n = 4;
    // cout<<"HELLO"<<"\n";
    // cout<<"HELLO"<<"\n";
    // // search(1, subset, 3);

    // for(int i=1; i<=5; i++){
    //     if(i==3 || i==4) continue;
    //     cout<<"Hello"<<i<<"\n";
    // }

    // int x = -43;
    // unsigned int y = x;
    // cout<<"x: "<<x<<"\n";
    // cout<<"y: "<<y<<"\n";

    int AND = 10&9;
    int OR = 10|9;
    int XOR = 10^9;
    int NOT = ~10;

    cout<<"AND: "<<AND<<"\n";
    cout<<"OR: "<<OR<<"\n";
    cout<<"XOR: "<<XOR<<"\n";
    cout<<"NOT: "<<NOT<<"\n";





    return 0;
}

