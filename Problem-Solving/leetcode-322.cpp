// Coin Change
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& dp, vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int ans = 1e9;
        for (auto x : coins) {
            if (amount - x >= 0) {
                ans = min(ans, coinChange(dp, coins, amount - x) + 1);
            }
        }

        return dp[amount] = ans;
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 0;
    vector<int> dp(amount + 1, -1);
    if (s.coinChange(dp, coins, amount) == 1e9) {
        cout << "-1";
    } else {
        cout << s.coinChange(dp, coins, amount);
    }
    for (auto x : dp) {
        cout << x << ",";
    }
}