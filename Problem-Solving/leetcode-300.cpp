// Longest increasing subsequece,Maximum Subarray.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
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
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    cout << s.lengthOfLIS(nums) << endl;
}