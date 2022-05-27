// Rotting Oranges.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    //  All Cordinates.
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        bool flag = false;

        // If no orage is fresh.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    flag = true;
                }
            }
        }

        if (!flag) {
            return 0;
        }

        queue<pair<int, int>> q;
        // Filling of rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto f = q.front().first;
            auto s = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newX = f + dx[k];
                int newY = s + dy[k];

                if (newX >= 0 and newY >= 0 and newX < m and newY < n and
                    grid[newX][newY] == 1) {
                    grid[newX][newY] = grid[f][s] + 1;
                    q.push({newX, newY});
                }
            }
        }

        int ans = 0;
        // If any orange after traversal remains fresh
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
                ans = max(ans, grid[i][j]);
            }
        }

        return ans - 2;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 1}, {0, 1, 2}};
    cout << s.orangesRotting(grid);
}
