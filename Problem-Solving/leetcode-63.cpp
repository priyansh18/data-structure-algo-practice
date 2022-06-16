// Unique Paths II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int helper(vector<vector<int>> obstacleGrid, vector<vector<int>>& dp, int i,
               int j, int m, int n) {
        if (i == m and j == n) return 1;

        if (obstacleGrid[i][j] == 1) return dp[i][j] = 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (i == m) {
            return helper(obstacleGrid, dp, i, j + 1, m, n);
        }

        if (j == n) {
            return helper(obstacleGrid, dp, i + 1, j, m, n);
        }

        return dp[i][j] = helper(obstacleGrid, dp, i + 1, j, m, n) +
                          helper(obstacleGrid, dp, i, j + 1, m, n);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(obstacleGrid, dp, 0, 0, m - 1, n - 1);
    }
};

int main() {
    Solution s;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> obstacleGrid2 = {{0, 1}, {0, 0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << s.uniquePathsWithObstacles(obstacleGrid2);
}