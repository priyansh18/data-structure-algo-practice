// Search in rotated array II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > nums[s]) {
                // It means mid is currently on first line
                if (nums[s] <= target and target < nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else if (nums[mid] < nums[s]) {
                if (nums[mid] <= target and target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            } else {
                s++;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << s.search(nums, target) << endl;
}