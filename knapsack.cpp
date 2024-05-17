#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0-1 knapsack problem
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // The maximum value that can be obtained
    return K[n][W];
}

int main() {
    int W = 50; // Capacity of knapsack
    vector<int> val = {60, 100, 120}; // Values of items
    vector<int> wt = {10, 20, 30}; // Weights of items
    int n = val.size(); // Number of items

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}

