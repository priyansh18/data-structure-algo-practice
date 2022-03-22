// Search Target Sum in rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isPresent(vector<int> nums, int target) {
        int n = nums.size();
        int i = 0;
        // Finding Pivot Element
        for (; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                break;
            }
        }

        int left = i + 1;
        int right = i;

        while (left != right) {
            if (nums[left] + nums[right] == target) {
                return true;
            } else if (nums[left] + nums[right] > target) {
                right = (n + right - 1) % n;
            } else {
                left = (left + 1) % n;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {11, 15, 26, 38, 9, 10};
    int targetSum = 35;
    cout << s.isPresent(nums, targetSum) << endl;
    targetSum = 45;
    cout << s.isPresent(nums, targetSum) << endl;
}