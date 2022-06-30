// Minimum Falling path sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[n - 1] = matrix[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int opt1 = INT_MAX;
                int opt2 = INT_MAX;
                int opt3 = INT_MAX;
                if (i + 1 >= 0 and i + 1 < n and j + 1 >= 0 and j + 1 < n) {
                    opt1 = dp[i + 1][j + 1];
                }

                if (i + 1 >= 0 and i + 1 < n and j - 1 >= 0 and j - 1 < n) {
                    opt2 = dp[i + 1][j - 1];
                }

                if (i + 1 >= 0 and i + 1 < n and j >= 0 and j < n) {
                    opt3 = dp[i + 1][j];
                }

                dp[i][j] = matrix[i][j] + min({opt1, opt2, opt3});
            }
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