// Coin Change II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // dp(i, taken)
    int helper(vector<vector<int>>& dp, int amount, vector<int>& coins,
               int taken) {
        int n = coins.size();
        if (taken == n) return 0;
        if (amount == 0) return 1;
        if (amount < 0) return 0;

        if (dp[amount][taken] != -1) return dp[amount][taken];

        return dp[amount][taken] =
                   helper(dp, amount - coins[taken], coins, taken) +
                   helper(dp, amount, coins, taken + 1);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(n + 1, -1));
        return helper(dp, amount, coins, 0);
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << s.change(amount, coins);
}