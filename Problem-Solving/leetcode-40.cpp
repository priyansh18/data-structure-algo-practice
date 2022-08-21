// Combination Sum  II

#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> ds;

    void helper(vector<int>& candidates, int s, int target) {
        if (target == 0) {
            ans.push_back(ds);
        }
        if (target < 0) {
            return;
        }

        for (int i = s; i < candidates.size(); i++) {
            if (i != s and candidates[i] == candidates[i - 1]) continue;
            ds.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i]);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return ans;
    }
};