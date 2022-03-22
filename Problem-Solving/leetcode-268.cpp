// Find the Missing Number in an array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Addition Operation
        int sum = n * (n + 1) / 2;

        for (auto x : nums) {
            sum -= x;
        }

        return sum;
    }

    int missingNumberXOR(vector<int>& nums) {
        int n = nums.size();

        int x1 = 0;
        int x2 = 0;

        for (auto x : nums) {
            x1 ^= x;
        }

        for (int i = 1; i <= n; i++) {
            x2 ^= i;
        }

        return x1 ^ x2;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 0, 1};
    cout << s.missingNumber(nums) << endl;
    cout << s.missingNumberXOR(nums) << endl;
}