// Target Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    
    int helper(vector<vector<int>> & dp,vector<int>& nums, int s, int e, int target) {
        if (s > e and target == 0) return 1;
        if (s > e and target != 0) return 0;
        
        if(dp[s][target+1000]!=-1) return dp[s][target+1000];
       
        // if(nums[s] == 0) return dp[s][target] = helper(dp,nums,s+1,e,target); 
        return dp[s][target+1000]= helper(dp,nums, s + 1, e, target - nums[s]) +
               helper(dp,nums, s + 1, e, target + nums[s]);
    }

    
    int helper2(vector<vector<int>> & dp,vector<int>& nums,  int target, int total, int s, int bag=0) {
        int n = nums.size();
        
        if(s == n) {
            if(bag - (total - bag) ==  target) return 1;
            return 0;
        }
        
        if( dp[s][bag]!=-1) return dp[s][bag];        
        int opt1 = helper2(dp,nums,target, total, s+1, bag + nums[s]);
        int opt2 = helper2(dp,nums,target, total, s+1, bag);
        
        return dp[s][bag] = opt1 + opt2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Method 1
        // vector<vector<int>> dp(n+1,vector<int> (200005,-1));
        // return helper(dp, nums, 0, n - 1, target);
        
        // Method 2
        vector<vector<int>> dp2(n+1,vector<int> (20005,-1));
        int total = accumulate(nums.begin(), nums.end(), 0);
        return helper2(dp2, nums, target, total,0);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int ans = 3;
    cout << s.findTargetSumWays(nums, ans);
}