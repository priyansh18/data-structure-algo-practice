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
            if (nums[mid] == target) {
                return mid;
            }  // Check if Mid lies on left line
            else if (nums[mid] >= nums[start]) {
                if (key >= nums[start] and key <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (key >= nums[mid] and key <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            // Check if Mid lies on right line
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << s.search(nums, target) << endl;
}