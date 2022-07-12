// House Robber II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dp[101][101];
    int helper(vector<int>& nums, int s, int e) {
        if (s > e) return 0;
        if (dp[s][e] != -1) return dp[s][e];
        return dp[s][e] = max(nums[s] + helper(nums, s + 2, e),
                              helper(nums, s + 1, e));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return max(helper(nums, 1, n - 1), helper(nums, 0, n - 2));
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums);
}