// Search in rotated sorted array

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[start] <= nums[mid]) {
                // Left Side is Sorted
                target >= nums[start] and target <= nums[mid] ? end = mid - 1
                                                              : start = mid + 1;
            } else {
                // Right Side is Sorted
                target >= nums[mid] and target <= nums[end] ? start = mid + 1
                                                            : end = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 8;
    cout << s.search(nums, target) << endl;
}