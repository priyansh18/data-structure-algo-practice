#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long dp[51][51][51];
    int M = 1e9 + 7;

    long long helper(int m, int n, int moves, int startRow, int startColumn,
                     int dx[], int dy[]) {
        if (dp[moves][startRow][startColumn] != -1)
            return dp[moves][startRow][startColumn];

        long long ways = 0;
        for (int k = 0; k < 4; k++) {
            int newX = startRow + dx[k];
            int newY = startColumn + dy[k];

            if (moves == 0) {
                if (newX < 0 or newY < 0 or newX >= m or newY >= n) {
                    ways++;
                }
            } else {
                if (newX >= 0 and newY >= 0 and newX < m and newY < n) {
                    ways += helper(m, n, moves - 1, newX, newY, dx, dy);
                    ways %= M;
                }
            }
        }

        return dp[moves][startRow][startColumn] = ways;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        long long ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < maxMove; i++) {
            ans += (helper(m, n, i, startRow, startColumn, dx, dy)) % M;
        }
        return ans % M;
    }
};

int main() {
    Solution s;
    int m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow = 0;
    int startColumn = 0;
    cout << s.findPaths(m, n, maxMove, startRow, startColumn) << endl;
}
