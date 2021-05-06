#include<bits/stdc++.h>
using namespace std;


// Reversing an array.
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
 
void reverseArray(int arr[],int start, int end){
    while(start<end){
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}


// Reversing a string
void swap(char *a, char *b){
    char temp = *a;
    *a=*b;
    *b=temp;
}
 
string reverseArray(string str, int start , int end){
    while (start<end)
    {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
    return str;
}


 int main(){

     int arr[] = {1,2,3,4,5,6,7,8,9};
     string s = "APFGMRZXIFPSXKOQDRRQJBBZ";
     cout<<"LEngth: "<<s.length()<<endl;
     int n = sizeof(arr)/sizeof(arr[0]);
    
    //  reverseArray(arr, 0, n-1);
    
     

    //  cout<<"Reversed Array:\n";
    //  for(int i=0; i<n; i++){
    //      cout<<arr[i]<<" ";
    //  }

    cout<<"Reversed String: "<<reverseArray(s, 0, s.length()-1)<<endl;
     cout<<endl;
     return 0;
 }