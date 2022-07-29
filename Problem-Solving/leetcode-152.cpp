// Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n);
        dp[0] = {nums[0], nums[0]};
        int maxAns = nums[0];
        for (int i = 1; i < n; i++) {
            int v1 = max({nums[i], nums[i] * (dp[i - 1].first),
                          nums[i] * (dp[i - 1].second)});
            int v2 = min({nums[i], nums[i] * (dp[i - 1].first),
                          nums[i] * (dp[i - 1].second)});
            dp[i] = {v1, v2};
            maxAns = max(maxAns, max(v1, v2));
        }
        return maxAns;
    }
};

int Solution::maxProduct(const vector<int>& A) {
    int n = A.size();
    int maxV = A[0];
    int minV = A[0];
    int maxEl = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < 0) {
            swap(maxV, minV);
        }
        maxV = max(A[i], A[i] * maxV);
        minV = min(A[i], A[i] * minV);
        maxEl = max(maxEl, maxV);
    }

    return maxEl;
}

int main() {}