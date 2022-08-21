// Shortest Path in binary matrix

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid,
            vector<vector<int>>& visited) {
        if (i == m - 1 and j == n - 1) return 1;
        int ans = 1e8;
        visited[i][j] = 1;
        for (int k = 0; k < 8; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                grid[newX][newY] == 0 and !visited[newX][newY]) {
                ans = min(ans, dfs(newX, newY, m, n, grid, visited) + 1);
            }
        }
        visited[i][j] = 0;
        return ans;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = dfs(0, 0, m, n, grid, visited);
        return ans == 1e8 ? -1 : ans;
    }
};

class Solution2 {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if (grid[0][0] == 1) return -1;
        q.push({0, 0});
        dist[0][0] = 1;
        int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == m - 1 and y == n - 1) return 1 + dist[x][y];
            for (int k = 0; k < 8; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                    dist[newX][newY] == 0) {
                    q.push({newX, newY});
                    dist[newX][newY] = 1 + dist[x][y];
                    if (newX == m - 1 and newY == n - 1)
                        return 1 + dist[newX][newY];
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    Solution2 s2;
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << s.shortestPathBinaryMatrix(grid);
    cout << s2.shortestPathBinaryMatrix(grid);
}