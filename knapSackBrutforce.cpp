
#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight, profit;
};

// Function to calculate the profit for a subset of items
int knapsackBruteForce(int n, int capacity, vector<Item>& items) {
    int maxProfit = 0;

    // Iterate through all subsets (from 0 to 2^n - 1)
    for (int subset = 0; subset < (1 << n); subset++) {
        int totalWeight = 0;
        int totalProfit = 0;

        // Check each bit of the subset to decide whether to include the item
        for (int i = 0; i < n; i++) {
            // If the i-th bit is set, include the i-th item in the subset
            if (subset & (1 << i)) {
                totalWeight += items[i].weight;
                totalProfit += items[i].profit;
            }
        }

        // If the total weight is within the capacity, update maxProfit
        if (totalWeight <= capacity) {
            maxProfit = max(maxProfit, totalProfit);
        }
    }

    return maxProfit;
}

int main() {
    int n, capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter items weight and profit: \n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
    }

    // Call brute-force knapsack solution
    int maxProfit = knapsackBruteForce(n, capacity, items);
    cout << "Maximum profit (Brute Force): " << maxProfit << endl;

    return 0;
}
