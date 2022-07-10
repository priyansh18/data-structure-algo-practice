// Path with maximum gold

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int profit(vector<vector<int>>& grid, int i, int j, int m, int n,
               vector<vector<int>>& visited) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int v = 0;
        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];

            if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                !visited[newX][newY] and grid[newX][newY] != 0) {
                visited[newX][newY] = 1;
                v = max(v, grid[newX][newY] +
                               profit(grid, newX, newY, m, n, visited));
                visited[newX][newY] = 0;
            }
        }
        return v;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    visited[i][j] = 1;
                    int val = grid[i][j] + profit(grid, i, j, m, n, visited);
                    ans = max(ans, val);
                    visited[i][j] = 0;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
    cout << s.getMaximumGold(grid) << endl;
}