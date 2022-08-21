// Combination Sum

class Solution {
   public:
    void helper(vector<int> candidates, int target, vector<vector<int>>& result,
                vector<int> ans, int i) {
        if (i == candidates.size()) {
            return;
        }
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(ans);
            return;
        }
        // Leave the current element permanently
        helper(candidates, target, result, ans, i + 1);
        // Take the element and can be taken in future.
        ans.push_back(candidates[i]);
        helper(candidates, target - candidates[i], result, ans, i);
        ans.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        helper(candidates, target, result, ans, 0);
        return result;
    }
};