// Climbing Stairs
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int climbStairsHelper(vector<int> &dp, int n) {
        if (n == 0 or n == 1) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] =
                   climbStairsHelper(dp, n - 1) + climbStairsHelper(dp, n - 2);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climbStairsHelper(dp, n);
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(35);
}