// Number of island.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> dy = {1, 0, -1, 0};
    vector<int> dx = {0, 1, 0, -1};
    void numIslandsHelper(vector<vector<char>>& grid, int i, int j, int m,
                          int n) {
        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];

            if (newX >= 0 and newY >= 0 and newX < m and newY < n and
                grid[newX][newY] == '1') {
                grid[newX][newY] = '2';
                numIslandsHelper(grid, newX, newY, m, n);
            }
        }
    }
    void numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '2';
                    numIslandsHelper(grid, i, j, m, n);
                    count++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << ",";
            }
            cout << endl;
        }

        cout << count << endl;
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    s.numIslands(grid);
}