#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
        
        int max = INT_MIN;
        int sum=0;
        // Your code here
        for(int i=0; i<n; i++){
            sum = sum + arr[i];
            if(max<sum){
                max = sum;
            }
            if(sum<0){
                sum = 0;
            }
        }
        
        return sum;
    }

int main(){

    int arr[] = {1,2,3,-2,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Max Sum is: "<<maxSubarraySum(arr,n);
    return 0;
}