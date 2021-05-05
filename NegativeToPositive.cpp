#include<bits/stdc++.h>
using namespace std;


// void rearrange(int arr[], int n){
//     int j=0;
//     for(int i=0; i<n; i++){
//         if(arr[i]<0){
//             if(i!=j){
//                 swap(arr[i], arr[j]);
//             }
//             j++;
//         }
//     }
// }

void rearrange(int arr[], int left, int right){
    while (left <= right){
        if(arr[left] < 0 && arr[right]<0){
            left++;
        } else if(arr[left] > 0 && arr[right]<0){
            swap(arr[left], arr[right]);
            left++;
            right--;
        } else if(arr[left] > 0 && arr[right] > 0){
            right--;
        } else {
            left++;
            right--;
        }
    }
    
}


int main(){

    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    // rearrange(arr, n);
    rearrange(arr, 0, n-1);


    cout<<"Elements in array arr:\n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;

}