#include<bits/stdc++.h>
using namespace std;

void swap(long long *first, long long *second){
    long long temp = *first;
    *first = *second;
    *second = temp;
}

long long MaximumValue(long long first, long long second){

    if(first > second){
        return first;
    }
    return second;
}

long long MinimumValue(long long first, long long second){

    if(first < second){
        return first;
    }
    return second;
}



long long maxArrayProduct(int *arr, int n) {
	    // code here

        if(n==1){
            return arr[0];
        }
        
        long long  max_so_far = arr[0];

        long long maxVal = arr[0];
        long long minVal = arr[0];


        for(int i=1; i<n; i++){
           
           // Here we are swapping the values of maxValue and minValue everytime a 
           // negative number arrives
           if(arr[i]<0){
               swap(&maxVal, &minVal);
           }


           // Minimum between the current value and the minValue so far.. 
           minVal = MinimumValue(arr[i], minVal*arr[i]);

           // Maximum between the current value and the maxValue so far.. 
           maxVal = MaximumValue(arr[i], maxVal*arr[i]);

            // Maximum between the max_so_far and maxVal to get the 
            // maximum sub-array product
            max_so_far = MaximumValue(max_so_far, maxVal);
        }

        return max_so_far;
}


int main(){

    int a[] = {6, -5};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Maximum product subarray is " <<maxArrayProduct(a, n);
    return 0;

}