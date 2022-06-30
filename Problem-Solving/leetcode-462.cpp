// Minimum Moves to Equal Array Elements II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = 0;
        if (n % 2 == 0) {
            int val1 = nums[n / 2 - 1];
            int val2 = nums[n / 2];
            median = (val1 + val2) / 2;
        } else {
            median = nums[n / 2];
        }

        int moves = 0;
        for (auto x : nums) {
            moves += abs(median - x);
        }

        return moves;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 10, 2, 6};
    cout << s.minMoves2(nums);
}