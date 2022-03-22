// Dutch National Flag Problem.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dutchNationalFlag(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int c = 0;
        int h = n - 1;

        while (c <= h) {
            if (nums[c] == 0) {
                // Pushing it to left side
                swap(nums[c], nums[l]);
                l++;
                c++;
            } else if (nums[c] == 1) {
                c++;
            } else {
                // Pushing it to right side

                swap(nums[c], nums[h]);
                h--;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 1, 2, 1, 2, 1};
    s.dutchNationalFlag(nums);
    for (auto x : nums) {
        cout << x << ",";
    }
}