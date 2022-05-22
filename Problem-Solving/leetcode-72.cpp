// Edit Distance

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minDistanceHelper(vector<vector<int>> &dp, string x, string y, int m,
                          int n) {
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        if (x[m - 1] == y[n - 1]) {
            return minDistanceHelper(dp, x, y, m - 1, n - 1);
        }
        return dp[m][n] = 1 + min({minDistanceHelper(dp, x, y, m - 1, n),
                                   minDistanceHelper(dp, x, y, m, n - 1),
                                   minDistanceHelper(dp, x, y, m - 1, n - 1)});
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return minDistanceHelper(dp, word1, word2, m, n);
    }
};

int main() {
    Solution s;
    string str1 = "horse";
    string str2 = "ros";
    cout << s.minDistance(str1, str2);
}