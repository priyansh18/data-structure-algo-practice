// Combination Sum IV

class Solution {
   public:
    int dp[1001];
    int helper(int n, vector<int> nums, int target) {
        if (target < 0) return 0;
        if (target == 0) return 1;

        if (dp[target] != -1) return dp[target];
        int ans = 0;
        for (auto x : nums) {
            ans += helper(n, nums, target - x);
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return helper(n, nums, target);
    }
};