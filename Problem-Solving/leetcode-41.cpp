// First Missing Positive;

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // converting all number in range
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 or nums[i] > n + 1) {
                nums[i] = n + 2;
            }
        }

        for (auto x : nums) {
            cout << x << ",";
        }
        cout << endl;

        for (auto v : nums) {
            int i = abs(v)-1;
            if (i >= 0 and i < n) {
                nums[i] = -abs(nums[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 0};
    cout << s.firstMissingPositive(nums) << endl;
}