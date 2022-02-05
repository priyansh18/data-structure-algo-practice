#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Top Down

int frogJumpTopDown(vector<int> height, int n, int i, vector<int> &dp) {
    if (i == n - 1) {
        return dp[i] = 0;
    }
    if (i == n - 2) {
        return dp[i] = abs(height[i] - height[i + 1]);
    }

    if (dp[i] != -1) return dp[i];

    int opt1 = abs(height[i + 1] - height[i]) + frogJumpTopDown(height, n, i + 1, dp);
    int opt2 = abs(height[i + 2] - height[i]) + frogJumpTopDown(height, n, i + 2, dp);
    return dp[i] = min(opt1, opt2);
}

// Bottom Up

int frogJumpBottomUp(vector<int> height, int n) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    for (int i = 2; i < n; i++) {
        int opt1 = dp[i - 1] + abs(height[i] - height[i - 1]);
        int opt2 = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(opt1, opt2);
    }

    return dp[n - 1];
}

int main() {
    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = height.size();
    cout << frogJumpBottomUp(height, n);
    cout << endl;
    vector<int> dp(n, -1);
    cout << frogJumpTopDown(height, n, 0,dp);
}