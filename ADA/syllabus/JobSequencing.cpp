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

    Job* schJobs[t]; // Scheduling of jobs
    int totalProfit = 0;
    for(int i = 0; i < t; i++)
        schJobs[i] = NULL;
    for(int i = 0; i < n; i++) {
            int currDeadline = jobs[i].deadline - 1;
            if(schJobs[currDeadline] == NULL) {
                *schJobs[currDeadline] = jobs[i];
                cout << "Placed at " << currDeadline << endl;
            }
            else {
                for(int j = currDeadline - 1; j >= 0; j--) {
                    if(schJobs[currDeadline] == NULL) {
                        *schJobs[currDeadline] = jobs[i];
                        cout << "Placed at " << j << endl;
                    }
                }
            }
    }
    cout << "\tTime\tJob\tProfit\n";
    for(int i = 0; i < t; i++) {
        cout  << "\t" << i << " - " << i + 1 << "\tJ" << schJobs[i]->id <<  "\t" << schJobs[i]->profit << "\n";
        totalProfit += schJobs[i]->profit;
    }
    return totalProfit;
}
int main() {
    int n;
    struct Job jobs[n];
    cout << "Enter number of jobs : ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        cout << "Enter profit and deadline of job " << i + 1 << " : ";
        cin >> jobs[i].profit >> jobs[i].deadline;
    }

    int profit = jobSeq(jobs, n);
    cout << "Maximum Profit : " << profit << "\n";
    return 0;
}