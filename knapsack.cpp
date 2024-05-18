#include <iostream>

using namespace std;

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    // Create a 2D array to store the maximum value that can be obtained
    // for the first i items with a knapsack capacity of j
    int dp[n + 1][W + 1];

    // Initialize the dp array with 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }

    // Build dp array in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            // If the current item's weight is more than the current capacity j,
            // then the current item cannot be included in the knapsack
            if (wt[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            // Otherwise, choose the maximum of including the current item or excluding it
            else {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }

    // The result is stored at dp[n][W]
    return dp[n][W];
}

// Main function
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
