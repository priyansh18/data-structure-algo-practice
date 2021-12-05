#include <iostream>
#include <vector>
using namespace std;

// Top-Down Knapsack
int knapsack(int wts[], int prices[], int N, int W) {
    // Base Case
    if (N == 0 or W == 0) {
        return 0;
    }
    int include = 0;
    int exclude = 0;
    if (W - wts[N - 1] >= 0) {
        include = prices[N - 1] + knapsack(wts, prices, N - 1, W - wts[N - 1]);
    }
    exclude = knapsack(wts, prices, N - 1, W);

    return max(include, exclude);
}
// Bottom-Up Knapsack
int knapsackDP(int wt[], int prices[], int N, int W) {
    vector<vector<int> > dp(N + 1, vector<int>(W + 1, 0));
    for (int n = 1; n <= N; n++) {
        for (int w = 1; w <= W; w++) {
            int include = 0;
            int exclude = 0;
            if (wt[n - 1] <= w) {
                include = prices[n - 1] + dp[n - 1][w - wt[n - 1]];
            }
            exclude = dp[n - 1][w];
            dp[n][w] = max(include, exclude);
        }
    }
    for (int n = 0; n <= N; n++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[n][w] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return dp[N][W];
}

int main() {
    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};

    cout << "Max Profits : " << knapsack(wts, prices, 4, 11) << endl;
    cout << "Max Profits : " << knapsackDP(wts, prices, 4, 11) << endl;
}