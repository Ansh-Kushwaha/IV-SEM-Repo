#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, profit, deadline;
};

bool compareTwoJobs(Job j1, Job j2) {
    return j1.profit >= j2.profit;
}

int jobSeq(struct Job jobs[], int n) {

    Job jobsC[n];
    for(int i = 0; i < n; i++)
        jobsC[i] = jobs[i];

    int orIdx[n];

    sort(jobsC, jobsC + n, compareTwoJobs);
    for(int i = 0; i < n; i++)
        orIdx[i] = jobsC[i].id;

    int t = 0; // Total time
    for(int i = 0; i < n; i++) {
        if(jobsC[i].deadline > t)
            t = jobsC[i].deadline;
    }

    int schJobs[t]; // Scheduling of jobs
    int totalProfit = 0;

    for(int i = 0; i < t; i++)
        schJobs[i] = 0;

    for(int i = 0; i < t; i++) {
        int d = jobsC[i].deadline;
        if(schJobs[d - 1] == 0) {
            schJobs[d - 1] = orIdx[i];
        }
        else {
            for(int j = d - 2; j >= 0; j--) {
                if(schJobs[j] == 0) {
                    schJobs[j] = orIdx[i];
                    break;
                }
            }
        }
    }

    cout << "\tTime\tJob\tProfit\n";
    for(int i = 0; i < t; i++) {
        cout  << "\t" << i << " - " << i + 1 << "\tJ" << jobs[schJobs[i] - 1].id <<  "\t" << jobs[schJobs[i] - 1].profit << "\n";
        totalProfit += jobs[schJobs[i] - 1].profit;
    }
    return totalProfit;
}
int main() {
    int n;
    cout << "Enter number of jobs : ";
    cin >> n;
    struct Job jobs[n];
    for(int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        cout << "Enter profit and deadline of job " << i + 1 << " : ";
        cin >> jobs[i].profit >> jobs[i].deadline;
    }

    int profit = jobSeq(jobs, n);
    cout << "Maximum Profit : " << profit << "\n";
    return 0;
}