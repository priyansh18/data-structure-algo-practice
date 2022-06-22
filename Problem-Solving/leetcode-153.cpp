// Minimum in rotated sorted array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;
        if (s == e) return nums[s];
        if (nums[0] < nums[n - 1]) return nums[0];

        while (s <= e) {
            int mid = (s + e) / 2;
            if (mid - 1 >= 0 and nums[mid] < nums[mid - 1]) return nums[mid];
            if (nums[mid] > nums[n - 1]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << s.findMin(nums) << endl;
}