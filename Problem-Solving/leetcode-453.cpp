// Minimum Moves to make array elements equal

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isEqual(vector<int> nums) {
        int n = nums.size();
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                flag = false;
            }
        }

        return flag;
    }

    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if (isEqual(nums)) {
            return 0;
        } else {
            while (!isEqual(nums)) {
                count++;
                sort(nums.begin(), nums.end());
                for (int i = 0; i < n - 1; i++) {
                    nums[i] += 1;
                }
                if (isEqual(nums)) {
                    return count;
                }
            }
        }

        return count;
    }
};

class Solution2 {
   public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int minEl = INT_MAX;
        for (auto x : nums) {
            minEl = min(minEl, x);
        }

        for (auto x : nums) {
            count += (x - minEl);
        }

        return count;
    }
};
int main() {
    Solution s;
    Solution2 s2;
    vector<int> nums = {1, 2, 3};
    vector<int> nums2 = {1, 2, 3};
    cout << s.minMoves(nums) << endl;
    cout << s2.minMoves(nums2) << endl;
}