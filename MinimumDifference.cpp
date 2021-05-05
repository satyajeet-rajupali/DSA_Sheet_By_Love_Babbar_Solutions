#include <bits/stdc++.h>
using namespace std;

// int getMinDiff(int arr[], int n, int k)
// {

//     if (n == 1)
//        return 0;

//     // Sort all elements
//     sort(arr, arr+n);

//     // Initialize result
//     int ans = arr[n-1] - arr[0];

//     // Handle corner elements
//     int small = arr[0] + k;
//     int big = arr[n-1] - k;
//     if (small > big)
//        swap(small, big);

//     // Traverse middle elements
//     for (int i = 1; i < n-1; i ++)
//     {
//         int subtract = arr[i] - k;
//         int add = arr[i] + k;

//         // If both subtraction and addition
//         // do not change diff
//         if (subtract >= small || add <= big)
//             continue;

//         // Either subtraction causes a smaller
//         // number or addition causes a greater
//         // number. Update small or big using
//         // greedy approach (If big - subtract
//         // causes smaller diff, update small
//         // Else update big)
//         if (big - subtract <= add - small)
//             small = subtract;
//         else
//             big = add;
//     }

//     return  min(ans, big - small);
// }

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    cout<<"Elements in array after sorting:\n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int ans = arr[n - 1] - arr[0];
    cout<<"Value of ans before while loop: "<<ans<<"\n";
    int x = 1;
    while (arr[x] - k < 0){
        cout<<"Values in while loop: "<<arr[x]<<"\n";
        x++;
    }
    cout<<"Value of x after while loop: "<<x<<endl;
    int loop = 1;
    for (; x < n; x++)
    {   
        cout<<"In loop: "<<loop<<endl;
        int mn = min(arr[0] + k, arr[x] - k);
        cout<<"Value of mn: "<<mn<<endl;
        int mx = max(arr[n - 1] - k, arr[x - 1] + k);
        cout<<"Value of mx: "<<mx<<endl;
        ans = min(mx - mn, ans);
        cout<<"Value of ans: "<<ans<<endl;
        loop++;        
    }
    return ans;

    //return 0;
}

int getMD(int arr[], int n, int k){

    sort(arr,arr+n);

    int ans = arr[n-1] - arr[0];
    int x = 1;

    while(arr[x-1]<0){
        x++;
    } 

    for( ; x<n; x++){
        int mn = min(arr[0] + k,0);
    }
    return 0;
}

int main()
{
    int Arr[] = {5, 5, 8, 6, 4, 10, 3, 8, 9, 10};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout<<"Ans: "<<getMinDiff(Arr, n, 5);
    return 0;
}