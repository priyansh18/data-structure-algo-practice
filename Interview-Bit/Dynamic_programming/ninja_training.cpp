#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[n - 1] = points[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            for (int k = 2; k >= 0; k--) {
                if (k != j) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][k]);
                }
            }
            dp[i][j] += points[i][j];
        }
    }

    return max(dp[0][0], max(dp[0][1], dp[0][2]));
}

int main() {
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = 3;
    cout << ninjaTraining(n, points);
}