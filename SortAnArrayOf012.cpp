#include<iostream>
using namespace std;

// void sort012(int a[], int n)
//     {
//         // coode here 
//         int arr[3] = {0};
        
//         for(int i=0; i<n; i++){
//             arr[a[i]]++;
//         }
//         int k=0,j=0;
//         while(k<3){
//             if(arr[k]>0){
//                 a[j++] = k;
//                 arr[k]--;
//             } else{
//                 k++;
//             }
//         }
//     }


// void sort012(int a[], int n){

//     int lo = 0;
//     int mid = 0;
//     int high = n-1;

//     while (mid<=high)
//     {
//         switch (a[mid])
//         {

//         //  If the element is 0    
//         case 0:
//             swap(a[lo++],a[mid++]);
//             break;

//         // If the element is 1
//         case 1:
//             mid = mid + 1;
//             break;    
        
//         // If the element is 2
//         case 2:
//             swap(a[mid], a[high--]);
//             break;
        

//         }
//     }
    
// }

void sort012(int arr[], int n){
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for(i=0; i<n; i++){

        switch (arr[i])
        {
        case 0:
            cnt0++;
            break;

        case 1:
            cnt1++;
            break;

        case 2:
            cnt2++;
            break;        
        
        }
    }

    i = 0;

    while (cnt0 > 0)
    {
        arr[i++] = 0;
        cnt0--;
    }

    while (cnt1 > 0)
    {
        arr[i++] = 1;
        cnt1--;
    }

    while (cnt2 > 0)
    {
        arr[i++] = 2;
        cnt2--;
    }
    
}


int main(){
    int A[] = {0,2,1,2,0};
    int n = sizeof(A)/sizeof(A[0]);
    sort012(A,n);

    cout<<"Elements in Array A[]:\n";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}