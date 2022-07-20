// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans = "";
        int i = m;
        int j = n;
        while (i > 0 and j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                ans += text1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(ans.begin(),ans.end());
        cout << ans << endl;

        return dp[m][n];
    }
};

int main() {
    Solution s;
    string text1 = "abcde";
    string text2 = "ace";
    cout << s.longestCommonSubsequence(text1, text2) << endl;
}