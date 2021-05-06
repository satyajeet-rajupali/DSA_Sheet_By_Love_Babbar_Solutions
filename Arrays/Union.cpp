#include<bits/stdc++.h>
using namespace std;

void doUnion(int a[], int n, int b[], int m){
    
     map<int, int> mp;

     for(int i=0; i<n; i++){
         mp.insert({a[i], i});
     }

     for(int i=0; i<m; i++){
         mp.insert({b[i], i});
     }
    
    cout<<"Elements of mp:\n";
     for(auto it = mp.begin(); it!=mp.end(); it++){
         cout<<it->first<<" ";
     }

     cout<<"\nSize of map: "<<mp.size();

}


int main(){

    int a[] = { 1, 3, 2, 3, 3, 4, 5, 5, 6 };
    int b[] = { 3, 3, 5 };
 
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
   
    // sort
    sort(a, a + n);
    sort(b, b + m);

   doUnion(a,n,b,m);
    cout<<endl;

    return 0;
}