// Increasing triplet Subsequence.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        vector<int> leftMin(n);
        leftMin[0] = nums[0];
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j + 1], nums[j]);
        }

        for (auto x : leftMin) cout << x << ",";
        cout<<endl;
        for (auto x : rightMax) cout << x << ",";
        cout<<endl;

        for (int i = 0; i < n; i++) {
            if (leftMin[i] < nums[i] and rightMax[i] > nums[i]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.increasingTriplet(nums) << endl;
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << s.increasingTriplet(nums2) << endl;
}