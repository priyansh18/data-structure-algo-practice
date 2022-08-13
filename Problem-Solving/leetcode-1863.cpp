// Sum of All Subset XOR Totals

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> v;
    void helper(int s, int n, vector<int> nums, vector<int>& res) {
        if (s == n) {
            v.push_back(res);
            return;
        }
        helper(s + 1, n, nums, res);
        res.push_back(nums[s]);
        helper(s + 1, n, nums, res);
        res.pop_back();
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        helper(0,n,nums,res);
        int sum = 0;
        for (auto x : v) {
            int ans = 0;
            for (auto c : x) {
                ans ^= c;
            }
            sum += ans;
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,1,6};
    cout << s.subsetXORSum(nums);
}