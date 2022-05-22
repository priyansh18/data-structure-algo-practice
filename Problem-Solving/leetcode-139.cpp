// Word Break
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool wordBreakHelper(vector<vector<int>>& dp, string s, set<string> st,
                         vector<string> wordDict, int i, int j) {
        if (j == s.length() - 1) return st.find(s.substr(i)) != st.end();

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (st.find(s.substr(i, j - i + 1)) != st.end()) {
            if (wordBreakHelper(dp, s, st, wordDict, j + 1, j + 1)) {
                return dp[i][j] = true;
            }
            return dp[i][j] = wordBreakHelper(dp, s, st, wordDict, i, j + 1);
        }

        return dp[i][j] = wordBreakHelper(dp, s, st, wordDict, i, j + 1);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for (auto x : wordDict) {
            st.insert(x);
        }

        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        return wordBreakHelper(dp, s, st, wordDict, 0, 0);
    }
};

int main() {
    Solution s;
    string str = "priyanshsinghal";
    vector<string> dict = {"singhal", "priyansh"};
    cout << s.wordBreak(str, dict);
}