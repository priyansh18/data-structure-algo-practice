// Jump Game

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canJumpHelper(vector<int>& dp, vector<int>& nums, int s, int e) {
        if (s == e) return true;
        if (s > e) return false;
        if (dp[s] != -1) return dp[s];
        for (int i = 1; i <= nums[s]; i++) {
            if (canJumpHelper(dp, nums, s + i, e)) return dp[s] = true;
        }

        return dp[s] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return canJumpHelper(dp, nums, 0, n - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 0, 4};
    cout << s.canJump(nums);
}