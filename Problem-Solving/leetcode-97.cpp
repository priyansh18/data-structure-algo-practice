// Interleaving String

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dp[101][101][201];
    bool helper(string s1, string s2, string s3, int i, int j, int k) {
        if (i == s1.length() and s2.substr(j) != s3.substr(k)) {
            return false;
        }
        if (i == s1.length() and s2.substr(j) == s3.substr(k)) {
            return true;
        }
        if (j == s2.length() and s1.substr(i) != s3.substr(k)) {
            return false;
        }
        if (j == s2.length() and s1.substr(i) == s3.substr(k)) {
            return true;
        }

        if (s1[i] != s3[k] and s2[j] != s3[k]) {
            return false;
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        bool ans = false;
        if (s1[i] == s3[k]) {
            ans |= helper(s1, s2, s3, i + 1, j, k + 1);
        }
        if (s2[j] == s3[k]) {
            ans |= helper(s1, s2, s3, i, j + 1, k + 1);
        }

        return dp[i][j][k] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3, 0, 0, 0);
    }
};

int main() {
    Solution s;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    cout << s.isInterleave(s1, s2, s3) << endl;
}