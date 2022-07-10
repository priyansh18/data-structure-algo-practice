// Word Break
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool helper(vector<vector<int>> &dp, string s, set<string> &dict, int i,
                int j) {
        if (j == s.length() - 1) return dict.find(s.substr(i)) != dict.end();
        if (dp[i][j] != -1) return dp[i][j];
        if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
            return dp[i][j] = helper(dp, s, dict, j + 1, j + 1) or
                              helper(dp, s, dict, i, j + 1);
        }
        return dp[i][j] = helper(dp, s, dict, i, j + 1);
    } 

    bool wordBreak(string s, vector<string> &wordDict) {
        set<string> dict;
        for (auto x : wordDict) dict.insert(x);
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(dp, s, dict, 0, 0);
    }
};

int main() {
    Solution s;
    string str = "priyanshsinghal";
    vector<string> dict = {"singhal", "priyansh"};
    cout << s.wordBreak(str, dict);
}