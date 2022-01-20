#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(int *arr1, int *arr2, int *arr3, int n1, int n2, int n3)
{

    vector<int> ans;
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3)
    {

        if (arr1[i] < arr2[j] && arr1[i] < arr3[k])
            i++;
        else if (arr2[j] < arr1[i] && arr2[j] < arr3[k])
            j++;
        else if (arr3[k] < arr2[j] && arr3[k] < arr1[i])
            k++;
        else if (arr1[i] == arr2[j] && arr1[i] == arr3[k])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
    }

    return ans;
}

int main()
{
    int arr1[] = {1, 5, 5};
    int arr2[] = {3, 4, 5, 5, 10};
    int arr3[] = {5, 5, 10, 20};

    vector<int> ans = commonElements(arr1, arr2, arr3,
                                     sizeof(arr1) / sizeof(arr1[0]),
                                     sizeof(arr2) / sizeof(arr2[0]),
                                     sizeof(arr3) / sizeof(arr3[0]));

    if (ans.empty())
        cout << "Nothing Returned";
    else
    {
        cout << "Elements in vector:\n";
        for (auto it = ans.begin(); it != ans.end(); it++)
            cout << *it << " ";
        cout << "\n";
    }
    return 0;
}