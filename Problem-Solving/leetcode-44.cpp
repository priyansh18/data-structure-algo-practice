// WildCard Matching

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dp[2001][2001];
    bool helper(string s, string p, int i, int j) {
        if (i == -1 and j == -1) return true;
        if (i == -1) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (j == -1) return false;

        if (dp[i][j] != -1) return dp[i][j];
        if (p[j] == s[i] or p[j] == '?') {
            return dp[i][j] = helper(s, p, i - 1, j - 1);
        }
        if (p[j] == '*') {
            return dp[i][j] = helper(s, p, i - 1, j) or helper(s, p, i, j - 1);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        int m = s.length() - 1;
        int n = p.length() - 1;
        return helper(s, p, m, n);
    }
};

int main() {
    Solution l;
    string s = "aa";
    string p = "a";
    cout << l.isMatch(s, p);
}