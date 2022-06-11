// Jump Game II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int jumpHelper(vector<int> &dp,vector<int> nums, int s, int e) {
        if (s >= e) return 0;
        int minVal = INT_MAX;
        if(dp[s]!=-1) return dp[s];
        for (int i = 1; i <= nums[s]; i++) {
            minVal = min(minVal, jumpHelper(dp,nums, s + i, e) + 1);
        }

        return dp[s] = minVal;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return jumpHelper(dp,nums, 0, n-1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.jump(nums) << endl;
}