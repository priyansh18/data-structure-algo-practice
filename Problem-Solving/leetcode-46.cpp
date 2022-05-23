// Permutations.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void permuteHelper(vector<int>& nums, int i, int n,
                       vector<vector<int>>& result) {
        if (i == n) {
            result.push_back(nums);
            return;
        }

        for (int k = i; k < n; k++) {
            swap(nums[i], nums[k]);
            permuteHelper(nums, i + 1, n, result);
            swap(nums[i], nums[k]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteHelper(nums, 0, nums.size(), result);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);
    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}