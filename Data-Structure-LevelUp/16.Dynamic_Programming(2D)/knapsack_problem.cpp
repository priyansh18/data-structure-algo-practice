#include <iostream>
#include <vector>
using namespace std;

// Top Down

int maximumProfitKnapsack(int N, int W, vector<int> weights,
                          vector<int> prices) {
    if (N == 0 or W == 0) {
        return 0;
    }

    int inc = 0;
    int exc = 0;

    if (weights[N - 1] <= W) {
        // Include Current Element
        inc = prices[N - 1] +
              maximumProfitKnapsack(N - 1, W - weights[N - 1], weights, prices);
    }
    exc = maximumProfitKnapsack(N - 1, W, weights, prices);
    return max(inc, exc);
}

// Bottom Up

int maximumProfitKnapsack_bottom(int N, int W, vector<int> weights,
                                 vector<int> prices) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            int inc = 0;
            int exc = 0;

            if (weights[i - 1] <= j) {
                inc = prices[i] + dp[i - 1][j - weights[i - 1]];
            }
            exc = dp[i - 1][j];

            dp[i][j] = max(inc, exc);
        }
    }

    for (auto x : dp) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }

    return dp[N][W];
}

int main() {
    int N = 4;
    int W = 11;
    vector<int> weights = {2, 7, 3, 4};
    vector<int> prices = {5, 20, 20, 10};
    cout << maximumProfitKnapsack(N, W, weights, prices) << endl;
    cout << maximumProfitKnapsack_bottom(N, W, weights, prices) << endl;
}