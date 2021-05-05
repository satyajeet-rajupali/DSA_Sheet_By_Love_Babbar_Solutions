#include<bits/stdc++.h>
using namespace std;

int maxElement(int arr[], int n){
    int max = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n){
    int max = maxElement(arr,n);
    int *count = new int[max+1];

    for(int i=0; i<max+1; i++)
        count[i]=0;   

    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    int i=0, j=0;
    while (i<max+1){
        if(count[i]>0){
            arr[j++] = i;
            count[i]--;
        } else{
            i++;
        }
    }
    
}



int main(){

    int A[] = {89,2,76,65,16,91,56,77,1,9};
    int n = sizeof(A)/sizeof(A[0]);

    countSort(A,n);

    cout<<"Sorted Elements are:\n";
    for(int k=0; k<n; k++)
        cout<<A[k]<<" ";
    cout<<"\n";


    return 0;
}