#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, profit, deadline;
};

bool compareTwoJobs(Job j1, Job j2) {
    return j1.profit >= j2.profit;
}

int jobSeq(struct Job jobs[], int n) {
    sort(jobs, jobs + n, compareTwoJobs);

    int t = 0; // Total time
    for(int i = 0; i < n; i++) {
        if(jobs[i].deadline > t)
            t = jobs[i].deadline;
    }

    int Profits[t]; // Scheduling of jobs
    int totalProfit = 0;
    for(int i = 0; i < t; i++)
        Profits[i] = 0;
    for(int i = 0; i < n; i++) {
        if(t != 0) {
            int currDeadline = jobs[i].deadline - 1;
            if(Profits[currDeadline] == 0) {
                Profits[currDeadline] = jobs[i].profit;
                totalProfit += jobs[i].profit;
            }
            else {
                for(int j = currDeadline - 1; j >= 0; j--) {
                    if(Profits[currDeadline] == 0) {
                        Profits[currDeadline] = jobs[i].profit;
                        totalProfit += jobs[i].profit;
                    }
                }
            }
        }
        t--;
    }
    cout << "\tTime\tJob\n";
    for(int i = 0; i < t; i++)
        cout  << "\t" << i << " - " << i + 1 << "\tJ" << jobs[i].id << "\n";
    return totalProfit;
}
int main() {
    int n;
    struct Job jobs[n];
    cout << "Enter number of jobs : ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        // jobs[i].id = i + 1;
        cout << "Enter profit and deadline of job " << i + 1 << " : ";
        cin >> jobs[i].profit >> jobs[i].deadline;
    }

    int profit = jobSeq(jobs, n);
    cout << "Maximum Profit : " << profit << "\n";
    return 0;
}