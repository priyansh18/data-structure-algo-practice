
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /*You are required to complete below method */

    int dp[1001][1001];
    int helper(string s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = helper(s, i + 1, j) + helper(s, i, j - 1) + 1;
        else {
            return dp[i][j] = helper(s, i + 1, j) + helper(s, i, j - 1) -
                              helper(s, i + 1, j - 1);
        }
    }

    int countPS(string str) {
        int n = str.length();
        dp[n][n];
        memset(dp, -1, sizeof(dp));
        return helper(str, 0, n - 1);
    }
};

int main() {
    Solution s;
    string str = "abca";
    cout << s.countPS(str);
}