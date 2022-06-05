#include <bits/stdc++.h>
using namespace std;

int SubsetCount(int arr[], int N, int A, int B)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {

            sum += arr[j];
            if (sum >= A and sum <= B)
            {
                cnt++;
                cout << "Sum: " << sum << "\n";
            }
        }
    }
    return cnt;
}



int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int ar[N];
    for (int i = 0; i < N; i++)
        cin >> ar[i];

    cout << "Count: " << SubsetCount(ar, N, A, B) << "\n";

    return 0;
}