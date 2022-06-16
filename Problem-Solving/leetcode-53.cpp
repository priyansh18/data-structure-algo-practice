// Maximum Subarray Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT_MIN;
        for (auto x : nums) {
            sum += x;
            max_sum = max(max_sum, sum);
            if (sum < 0) sum = 0;
        }
        return max_sum;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;
}