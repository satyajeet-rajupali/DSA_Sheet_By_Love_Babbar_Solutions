#include <bits/stdc++.h>
using namespace std;

// Input:
// n1 = 6; A = {1, 5, 10, 20, 40, 80}
// n2 = 5; B = {6, 7, 20, 80, 100}
// n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
// Output: 20 80
// Explanation: 20 and 80 are the only
// common elements in A, B and C.


// Function to find the intersection of three distinct arrays.
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{   
    // vector container to store all the elements which are common in all three arrays.
    vector<int> cm;

    int i=0, j=0, k=0;

    // These variables to keep track of the previous elements.
    int prev1, prev2, prev3;

    prev1 = prev2 = prev3 = INT_MIN;

    // To traverse through three arrays
    while (i < n1 && j < n2 && k < n3)
    {
        // This is to increament i if current element is equal to the 
        // previous element in A[i].
        while (A[i] == prev1 && i < n1)
        {
            i++;
        }

        // This is to increament j if current element is equal to the 
        // previous element in B[j].
        while (B[j] == prev2 && j < n2)
        {
            j++;
        }

        // This is to increament k if current element is equal to the 
        // previous element in C[k].    
        while (C[k] == prev3 && k < n3)
        {
            k++;
        }
        
        // This part of the code is to fill the vector cm with all the 
        // the elements that are present in all the three arrays and also
        // update the prev1, prev2 and prev3 and increament the i,j and k.
        if (A[i] == B[j] && B[j] == C[k])
        {
            cm.push_back(A[i]);
            prev1 = A[i];
            prev2 = B[j];
            prev3 = C[k];

            i++;
            j++;
            k++;
           
        }

        // This condition will be implemented if A[i]<B[j] then prev1 will
        // be updated and i will be increament.
        else if (A[i] < B[j])
        {
            prev1 = A[i];
            i++;
        }

        // This condition will be implemented if B[j]<C[k] then prev2 will
        // be updated and j will be increament.
        else if (B[j] < C[k])
        {
            prev2 = B[j];
            j++;
        }
        
        // This condition will be implemented if C[k]<B[j] and C[k]<A[i] 
        // then prev3 will be updated and k will be increament.
        else
        {
            prev3 = C[k];
            k++;
        }
    }

    return cm;
}




int main()
{
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    

   vector<int> ce = commonElements(A, B, C, sizeof(A)/sizeof(A[0]), sizeof(B)/sizeof(B[0]), sizeof(C)/sizeof(C[0]));

    cout << "Elements in ce vector:\n";
    for (auto it = ce.begin(); it != ce.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}