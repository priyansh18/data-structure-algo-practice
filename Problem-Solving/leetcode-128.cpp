// Longest Consecutive Sequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // If smaller number already present in a set then it must have been
            // covered or cover later by some element;
            if (s.find(nums[i] - 1) != s.end()) continue;
            int count = 1;
            int temp = nums[i];
            while (s.find(temp + 1) != s.end()) {
                count++;
                temp = temp + 1;
            }
            ans = max(count, ans);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;
}