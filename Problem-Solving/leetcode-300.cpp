// Maximum Subarray.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int max_value = INT_MIN;
        for (auto x : dp) {
            max_value = max(x, max_value);
        }

        return max_value;
    }

    int LengthofLISOpt(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int length = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                length++;
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                temp[idx] = nums[i];
            }
        }

        return length;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    cout << s.lengthOfLIS(nums) << endl;
    cout << s.LengthofLISOpt(nums) << endl;
}