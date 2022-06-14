// Max Area of Island
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(vector<vector<int>> grid, vector<vector<bool>>& visited, int i,
            int j, int m, int n) {
        visited[i][j] = true;
        int current_size = 1;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];

            if (newX >= 0 and newY >= 0 and newX < m and newY < n and
                grid[newX][newY] == 1 and !visited[newX][newY]) {
                int subComponent = dfs(grid, visited, newX, newY, m, n);
                current_size += subComponent;
            }
        }

        return current_size;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int largest_island = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] and grid[i][j] == 1) {
                    int value = dfs(grid, visited, i, j, m, n);
                    largest_island = max(largest_island, value);
                }
            }
        }

        return largest_island;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << s.maxAreaOfIsland(grid);
}