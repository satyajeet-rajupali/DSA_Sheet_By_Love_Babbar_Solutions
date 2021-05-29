#include <bits/stdc++.h>
using namespace std;

// Program Idea:
// The idea here is to sort the array in ascending order so that all the elements that are placed 
// randomly in the array will be positioned according to the ascending order and then we will create 
// another array called "reserve_array" to eliminate the duplicate elements and store all the  
// unique element in the reserve_array and then we will check for the consecutive elements in the
// array and the consecutive sequence will be returned.

int findLongestConseqSubseq(int arr[], int n)
{
    //Your code here
    if(n == 1){
        return 1;
    }
    // Here we will sort the array.
    sort(arr, arr + n);

    // cout<<"Elements in array:\n";
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    int reserve_array[n] = {0};
    int cnt=0,i=1;

    while (i<n)
    {
        if(arr[i-1] != arr[i]){
            reserve_array[cnt] = arr[i-1];
            cnt++;
        }
        i++;
    }
    // cout<<"Value count: "<<cnt<<"\n";
    // cout<<"Value i: "<<i<<"\n";
    // reserve_array[cnt] = arr[i-1];
    cnt++;



    // cout<<"Value count: "<<cnt<<"\n";
    // cout<<"Elements in reserve array:\n";
    // for(int i=0; i<cnt; i++){
    //     cout<<reserve_array[i]<<" ";
    // }
    // cout<<endl;


    int consecSubArray = 0, maxconsecSubArray = 0;

    for (int i = 1; i < cnt; i++)
    {
        if (reserve_array[i] - reserve_array[i - 1] == 1)
            {
                consecSubArray++;
                 if (maxconsecSubArray < consecSubArray)
                {
                    maxconsecSubArray = consecSubArray;
                }

            }
            else
            {
                if (maxconsecSubArray < consecSubArray)
                {
                    maxconsecSubArray = consecSubArray;
                }
                consecSubArray = 0;
            }        
    }

    return maxconsecSubArray + 1;
}

int main()
{

    int a[] =  {1, 2, 3, 4, 5};   //  {8, 9, 1, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Longest consecutive numbers is " << findLongestConseqSubseq(a, n);
    return 0;
}