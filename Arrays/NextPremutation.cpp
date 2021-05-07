#include <bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int> &nums)
{   
    // With this code we are checking here the size of nums vector, 
    // if in case it is 1 or less than 1, the implementation will be stopped.
    if(nums.size()<=1){
        return;
    }


    int i = nums.size()-2;
    // With this code we are searching for the element nums[i] which is lesser than the
    // nums[i+1] from the opposite end of the vector.
    while (i>=0 && nums[i+1]<=nums[i])
    {
        i--;
    }

    // This snippet will be implemented if all elements in vector nums is in descending order. 
    if(i<0){
        reverse(nums.begin(), nums.end());
    }

    // With this code snippet we are looking for the element from the opposite side of the 
    // vector which is just larger than the element at 'i' position. 
    if(i>=0){
        int j = nums.size()-1;
        
        while( j>=0 && nums[j]<=nums[i]){
            j--;
        }
        // Elements at i and j position will be swapped here.
        swap(nums[j],nums[i]);

        // Here, the elements which are present at positions after 'i'th will be reversed to obtain
        // the required next permutation.
        reverse(nums.begin()+i +1, nums.end());

    }
    

    // To print the elements in vector
    // cout<<"Elements in nums vector:\n";
    // for(auto it=nums.begin(); it!=nums.end(); it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;

    
}




int main()
{
    //vector<int> v = {3,2,1};
    vector<int> v = {1,2,3};
    nextPermutation(v);
    return 0;
}