// Subarray Sum equals k

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int count = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            int val = sum - k;
            if (m.count(val) != 0) {
                count += m[val];
            }
            m[sum]++;
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1};
    int k = 3;
    cout << s.subarraySum(nums,k);
}