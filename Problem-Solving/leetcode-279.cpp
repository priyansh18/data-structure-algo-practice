// Perfect Squares

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int helper(int n, vector<int> &dp) {
        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        int ans = 1e9;

        for (int i = 1; i * i <= n; i++) {
            ans = min(ans, helper(n - i * i, dp) + 1);
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};

int main() {
    Solution s;
    int n = 12;
    cout << s.numSquares(n);
}