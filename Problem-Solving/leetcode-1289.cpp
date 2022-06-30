// Minimum Falling Path Sum II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        dp[n - 1] = grid[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int opt1 = 1e9;
                for (int k = n - 1; k >= 0; k--) {
                    if (k != j and k >= 0 and k < n) {
                        opt1 = min(opt1, dp[i + 1][k]);
                    }
                }
                dp[i][j] = grid[i][j] + opt1;
            }
        }

        for (auto x : dp) {
            for (auto y : x) {
                cout << y << ",";
            }
            cout << endl;
        }

        int minAns = INT_MAX;
        for (auto x : dp[0]) {
            minAns = min(minAns, x);
        }

        return minAns;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{100, -42, -46, -41},
                                  {31, 97, 10, -10},
                                  {-58, -51, 82, 89},
                                  {51, 81, 69, -51}};
    cout << s.minFallingPathSum(matrix);
}
