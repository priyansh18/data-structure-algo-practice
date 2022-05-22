#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cost;
vector<vector<int>> dp;
int n = 3;

// dp(i)
// dp(i), -> LIS, Kadane
// dp(i, taken) -> knapsack
// dp(l,r) -> MCM 
// dp(i,j) -> s[-....i] s[0,,.....j]


int minimumCost(int i, int j) {
    if (i == n) {
        return 0;
    }

    if (dp[i][j] != 1e9) return dp[i][j];

    return dp[i][j] = min(
               {cost[i][0] + min(minimumCost(i + 1, 1), minimumCost(i + 1, 2)),
                cost[i][1] + min(minimumCost(i + 1, 0), minimumCost(i + 1, 2)),
                cost[i][2] +
                    min(minimumCost(i + 1, 0), minimumCost(i + 1, 1))});
}

int minimumCostIter() {
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int j = 0; j < 3; j++) {
        dp[0][j] = cost[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dp[i][j] = cost[i][j] + min(dp[i - 1][1], dp[i - 1][2]);
            }
            if (j == 1) {
                dp[i][j] = cost[i][j] + min(dp[i - 1][0], dp[i - 1][2]);
            }
            if (j == 2) {
                dp[i][j] = cost[i][j] + min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return min({dp[n-1][0],dp[n-1][1], dp[n-1][2]});
}

int main() {
    cost = vector<vector<int>>{{14, 2, 11}, {11, 14, 5}, {14, 3, 10}};
    dp = vector<vector<int>>(n, vector<int>(3, 1e9));
    cout << minimumCost(0, 0) << endl;
    cout << minimumCostIter() << endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}