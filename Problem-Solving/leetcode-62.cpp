// Unique Paths

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int uniquePathsHelper(vector<vector<int>> &dp, int m, int n) {
        if (m == 1 and n == 1) return 1;

        if (dp[m][n] != -1) return dp[m][n];

        if (m == 1) return uniquePathsHelper(dp, m, n - 1);

        if (n == 1) return uniquePathsHelper(dp, m - 1, n);

        return dp[m][n] = uniquePathsHelper(dp, m, n - 1) +
                          uniquePathsHelper(dp, m - 1, n);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return uniquePathsHelper(dp, m, n);
    }
};

int main() {
    Solution s;
    int m = 3;
    int n = 2;
    cout << s.uniquePaths(m, n) << endl;
}