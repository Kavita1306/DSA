#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n+1][capacity+1];

    // Initialize the first row and column with zeros
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // Fill the dp array using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i-1] > j) // If the current item's weight is greater than the capacity, skip it
                dp[i][j] = dp[i-1][j];
            else
                // Calculate the maximum value of including or excluding the current item
                dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
        }
    }

    return dp[n][capacity]; // Return the maximum value
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weights[n], values[n];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &weights[i], &values[i]);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    int max_value = knapsack(weights, values, n, capacity);
    printf("Maximum value that can be put into the knapsack: %d", max_value);
    return 0;
}
