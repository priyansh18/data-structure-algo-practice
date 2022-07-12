// Longest Palindromic Subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dp[1005][1005];
    int helper(string s, int i, int j) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;

        if (s[i] == s[i]) {
            ans = 1 + helper(s, i + 1, j - 1);
        } else {
            ans = max(helper(s, i + 1, j), helper(s, i, j - 1)) + 1;
        }

        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, s.length() - 1);
    }
};

int main() {
    Solution k;
    string s = "cbbd";
    cout << k.longestPalindromeSubseq(s);
}
