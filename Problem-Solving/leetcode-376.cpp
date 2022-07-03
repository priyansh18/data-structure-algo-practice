// Wiggle Sequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int signum(int x) {
        if (x > 0) {
            return 1;
        }
        if (x < 0) {
            return -1;
        }

        return 0;
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // Minimum Length is always 1
        int ans = 1;

        int previous_sign = 0;

        for (int i = 1; i < n; i++) {
            int curr_sign = signum(nums[i] - nums[i - 1]);

            if (curr_sign != previous_sign and curr_sign != 0) {
                ans++;
                previous_sign = curr_sign;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    cout << s.wiggleMaxLength(nums);
}