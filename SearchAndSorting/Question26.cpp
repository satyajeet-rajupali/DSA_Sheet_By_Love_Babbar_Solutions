#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, profit;
};

bool functionJobs(Job s1, Job s2)
{
    return s1.finish < s2.finish;
}

void printFunction(Job j[], int N)
{
    cout << "Elements in jobs array:\n";
    for (int i = 0; i < N; i++)
        cout << "Start: " << j[i].start << " Finish: " << j[i].finish << " Profit: " << j[i].profit << "\n";
}

int latestNonConflict(Job jobs[], int N)
{
    for (int i = N - 1; i >= 0; i--)
        if (jobs[i].finish <= jobs[N - 1].start)
            return i;
    return -1;
}

int maxProfitUtil(Job jobs[], int N)
{

    if (N == 1)
        return jobs[N - 1].profit;

    int inclprofit = jobs[N - 1].profit;
    int i = latestNonConflict(jobs, N);

    if (i != -1)
    {
        inclprofit += maxProfitUtil(jobs, i + 1);
    }

    int exclProfit = maxProfitUtil(jobs, N - 1);

    return max(inclprofit, exclProfit);
}

int maxProfit(Job jobs[], int N)
{
    sort(jobs, jobs + N, functionJobs);
    return maxProfitUtil(jobs, N);
}

int main()
{
    Job jobs[] = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    int N = sizeof(jobs) / sizeof(jobs[0]);
    // cout << "Before Sorting:\n";
    // printFunction(jobs, N);

    // sort(jobs, jobs + N, functionJobs);

    // cout << "After Sorting:\n";
    // printFunction(jobs, N);
    cout << "Max Profit: " << maxProfit(jobs, N) << "\n";
    return 0;
}