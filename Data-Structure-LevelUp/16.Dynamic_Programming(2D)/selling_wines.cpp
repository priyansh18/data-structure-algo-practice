#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int> prices, int i, int j, int y,
                  vector<vector<int>> &dp) {
    if (i > j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int opt1 = prices[i] * y + maximumProfit(prices, i + 1, j, y + 1, dp);
    int opt2 = prices[j] * y + maximumProfit(prices, i, j - 1, y + 1, dp);

    return dp[i][j] = max(opt1, opt2);
}

int maximumProfit_BottomUp(vector<int> prices, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                dp[i][j] = max(prices[i] * (n - j + i) + dp[i + 1][j],
                               prices[j] * (n - j + i) + dp[i][j - 1]);
            }
        }
    }

    for (auto x : dp) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
    cout << endl;

    return dp[0][n - 1];
}

int main() {
    vector<int> prices = {2, 3, 5, 1, 4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << maximumProfit(prices, 0, n - 1, 1, dp) << endl;

    for (auto x : dp) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
    cout << endl;

    cout << maximumProfit_BottomUp(prices, n) << endl;
}
