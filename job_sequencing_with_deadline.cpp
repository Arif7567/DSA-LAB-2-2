#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

// Sorting by profit (descending order)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter Number of Jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter Job id, deadline, profit for each job:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Step 1: Sort jobs by profit (highest first)
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Step 3: Create a time slot array
    vector<int> slot(maxDeadline + 1, -1); // -1 means empty
    int totalProfit = 0;

    // Step 4: Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) { // free slot পাওয়া গেছে
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Step 5: Output result
    cout << "Selected Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            cout << slot[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
