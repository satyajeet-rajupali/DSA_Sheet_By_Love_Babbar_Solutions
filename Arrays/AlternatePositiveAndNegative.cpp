#include<bits/stdc++.h>
using namespace std;


// Input:  arr[] = {1, 2, 3, -4, -1, 4}
// Output: arr[] = {-4, 1, -1, 2, 3, 4}

// {-4, -1, 1, 2, 3, 4}


void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



void rightRotate(int a[], int n, int outOfPlace, int cur){

    cout<<"Elements in array before rightRotation:\n";
    print(a,n);
    cout<<endl;

    int temp = a[cur];

    for(int i=cur; i>outOfPlace; i--){
        a[i] = a[i-1];
    }

    a[outOfPlace] = temp;


    cout<<"Elements in array after rightRotation:\n";
    print(a,n);
    cout<<endl;
}


// Approach with O(N*N) time complexity.
// In this approach we are rearranging the elements by performing right rotation
void rearrange(int arr[], int n){

    int outOfPlace = -1;

    for(int index=0; index<n; index++){

        if(outOfPlace>=0){

            if((arr[index]>=0 && arr[outOfPlace]<0) || (arr[index]<0 && arr[outOfPlace]>=0)){

                rightRotate(arr, n, outOfPlace, index);
            }

            if(index - outOfPlace>=0){
                outOfPlace = outOfPlace + 2;

            } else{
                outOfPlace = -1;
            }
        }

        if(outOfPlace == -1){

            if(((arr[index]>=0) && !(index & 0x01)) || ((arr[index]<0) && (index & 0x01))){
                outOfPlace = index;
            }
        }
    }

    cout<<"Elements after sorting:\n";
    print(arr, n);
    cout<<endl;
}


// Approach with O(N) time complexity.
// In this approach we are clustering all the positive elements on the left side and negative 
// elements on the right side and then we are performing the alternate swapping to arrange
// them in alternate orders.
void alternatePositiveAndNegative(int *arr, int n){

    int posIndex=-1, negIndex=n;

    while (posIndex<negIndex)
    {
        // This clusters all the positive elements on the left side.
        while(posIndex<n && arr[posIndex]>=0){
            posIndex++;
        
        }
        // This clusters all the negative elements on the right side.
        while(negIndex>=0 && arr[negIndex]<0){
            negIndex--;
            

        }

        // Here swapping occurs to put them at their respective positions.
        if(posIndex<negIndex){
            swap(arr[posIndex], arr[negIndex]);
        }



    }

    // This will return if all the elements present in array are positive.
    if(posIndex == 0 || posIndex == n){
        return;
    }

    int k = 0;

    // Here, the swapping will be performed to arrange them in the alternate
    // positive and negative positions.
    while (k<n && posIndex<n)
    {
        swap(arr[k], arr[posIndex]);
        posIndex++;
        k+=2;
    }
    
    cout<<"Elements in the array:\n";
    print(arr,n);
    cout<<endl;
}


int main(){

    //int arr[] = {1, 2, 3, -4, -1, 4};
    // {-8,-5,-2, 0,1,2,4,5,7,8}
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    alternatePositiveAndNegative(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}