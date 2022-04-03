// Find Peak Element in O(logn) time.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 2, 1};
    cout << s.findPeakElement(nums) << endl;
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << s.findPeakElement(nums2) << endl;
    vector<int> nums3 = {5, 4, 3, 2, 1};
    cout << s.findPeakElement(nums3) << endl;
}