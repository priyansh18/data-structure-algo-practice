// Jump Game VI

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int helper(vector<int>& nums, int k, int s, int e, int n, vector<int>& dp) {
        if (s > e) return INT_MIN;
        if (s == e) return nums[e];

        int ans = 0;
        if (dp[s] != -1) return dp[s];
        int last_index = min(n - 1, s + k);
        for (int i = s + 1; i <= last_index; i++) {
            ans = max(ans, helper(nums, k, i, e, n, dp) + nums[s]);
        }

        return dp[s] = ans;
    }

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, k, 0, n - 1, n, dp);
    }
};

class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), a = 0, b = 0;
        deque<int> deq(n);
        deq[0] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (deq[a] - i > k) a++;
            nums[i] += nums[deq[a]];
            while (b >= a && nums[deq[b]] <= nums[i]) b--;
            deq[++b] = i;
        }
        return nums[0];
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, -5, -2, 4, 0, 3};
    int k = 3;

    cout << s.maxResult(nums, k);
}