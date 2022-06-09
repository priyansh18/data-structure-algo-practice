// Continious subarray sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; i++) {
            int val = prefixSum[i] % k;
            if (m.find(val) != m.end()) {
                if (i - m[val] > 1) return true;
            } else {
                m[val] = i;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {23, 2, 4, 6, 7};
    cout << s.checkSubarraySum(nums, 6);
}