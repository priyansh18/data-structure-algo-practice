// Missing number in arithmetic progression.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMissing(vector<int> &nums) {
        int n = nums.size();
        int d1 = nums[1] - nums[0];
        int d2 = nums[n - 1] - nums[n - 2];
        int d = min(d1, d2);

        int s = 0;
        int e = n - 1;

        while (s < e) {
            int mid = (s + e) / 2;
            if (nums[0] + mid * d < nums[mid]) {
                e = mid - 1;
            } else if (nums[0] + mid * d >= nums[mid]) {
                s = mid + 1;
            }
        }
        if (s == e) {
            if (nums[0] + s * d != nums[s]) {
                return nums[0] + s * d;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 2, 4, 8, 10, 12, 14};
    cout << s.findMissing(nums) << endl;
}