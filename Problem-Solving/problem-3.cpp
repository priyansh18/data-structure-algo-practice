// Partition Equal Subset Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftPrefixSum(n);
        leftPrefixSum[0] = nums[0];
        vector<int> rightPrefixSum(n);
        rightPrefixSum[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            leftPrefixSum[i] = leftPrefixSum[i - 1] + nums[i];
        }

        for (int j = n - 2; j >= 0; j--) {
            rightPrefixSum[j] = rightPrefixSum[j + 1] + nums[j];
        }

        for (auto x : leftPrefixSum) cout << x << ",";
        cout << endl;
        for (auto x : rightPrefixSum) cout << x << ",";
        cout << endl;

        for (int i = 0; i < n - 1; i++) {
            if (leftPrefixSum[i] == rightPrefixSum[i + 1]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 5};
    cout << s.canPartition(nums) << endl;
    vector<int> nums2 = {4,1,2,3};
    cout << s.canPartition(nums2) << endl;
    vector<int> nums3 = {4,3,2,1};
    cout << s.canPartition(nums3) << endl;
}