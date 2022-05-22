#include <bits/stdc++.h>
using namespace std;

int knapsackProfit(vector<vector<int>> &dp, int N, int W, vector<int> weights,
                   vector<int> prices) {
    if (N == 0) {
        return 0;
    }

    if (dp[N - 1][W - 1] != -1) {
        return dp[N - 1][W - 1];
    }

    int inc = 0;
    int exc = 0;

    if (weights[N - 1] <= W) {
        inc = knapsackProfit(dp, N, W - weights[N - 1], weights, prices) +
              prices[N - 1];
    }
    exc = knapsackProfit(dp, N - 1, W, weights, prices);

    return dp[N - 1][W - 1] = max(inc, exc);
}

int main() {
    int N = 3;
    int W = 100;
    vector<int> weights = {5, 10, 15};
    vector<int> prices = {10, 30, 20};
    vector<vector<int>> dp(N, vector<int>(W, -1));
    cout << knapsackProfit(dp, N, W, weights, prices);
    cout << endl;
    for (auto x : dp) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}