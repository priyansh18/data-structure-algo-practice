// Minimum Path Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minPathSumHelper(vector<vector<int>> grid, vector<vector<int>>& dp,
                         int i, int j, int m, int n) {
        if (i == m - 1 and j == n - 1) return grid[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        if (i == m - 1)
            return grid[i][j] + minPathSumHelper(grid, dp, i, j + 1, m, n);

        if (j == n - 1)
            return grid[i][j] + minPathSumHelper(grid, dp, i + 1, j, m, n);

        return dp[i][j] =
                   grid[i][j] + min(minPathSumHelper(grid, dp, i, j + 1, m, n),
                                    minPathSumHelper(grid, dp, i + 1, j, m, n));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minPathSumHelper(grid, dp, 0, 0, m, n);
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    cout << s.minPathSum(grid);
}