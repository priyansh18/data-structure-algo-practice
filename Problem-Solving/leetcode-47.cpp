// Permutations II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void permuteUniqueHelper(vector<int> &nums, int s, int e,
                             vector<vector<int>> &result) {
        if (s == e) {
            result.push_back(nums);
            return;
        }
        for (int i = s; i < e; i++) {
            swap(nums[i], nums[s]);
            permuteUniqueHelper(nums, s + 1, e, result);
            swap(nums[i], nums[s]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        permuteUniqueHelper(nums, 0, nums.size(), result);
        map<vector<int>, int> m;

        for (auto x : result) {
            m[x]++;
        }
        vector<vector<int>> res;
        for (auto x : m) {
            res.push_back(x.first);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = s.permuteUnique(nums);
    for (auto x : result) {
        for (auto y : x) {
            cout << y << ",";
        }
        cout << endl;
    }
}