// Equal Partition Sum

class Solution {
   public:
    int dp[20005][201];
    bool helper(vector<int>& nums, int sum1, int total, int n) {
        if (n == 0 and sum1 != total - sum1) return false;
        if (n == 0 and sum1 == total - sum1) return true;
        if (dp[sum1][n] != -1) return dp[sum1][n];
        return dp[sum1][n] = helper(nums, sum1 + nums[n - 1], total, n - 1) or
                             helper(nums, sum1, total, n - 1);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int sum1 = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        return helper(nums, sum1, total, n);
    }
};