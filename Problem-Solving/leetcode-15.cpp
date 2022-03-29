// Find the triplets whose sum is 0 and doesn't contain same elements.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> s;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        for (auto x : s) {
            result.push_back(x);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, 4};

    vector<vector<int>> result = s.threeSum(nums);

    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}