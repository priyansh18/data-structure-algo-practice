#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int helper(int n, vector<int> &dp) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = (n - 1) * (helper(n - 1, dp) + helper(n - 2, dp));
    }

    int countDerangements(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, -1);
        return helper(nums.size(), dp);
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 3};
    cout << s.countDerangements(nums) << endl;
}