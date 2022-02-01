#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j,int m, int n) {
    // Mark node as visited
    visited[i][j] = true;
    int cs = 1;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int newX = i + dx[k];
        int newY = j + dy[k];

        if (newX >= 0 and newY >= 0 and newX < m and newY < n and
            grid[newX][newY] == 1 and !visited[newX][newY]) {
            int subcomponent = dfs(grid, visited, newX, newY, m, n);
            cs += subcomponent;
        }
    }
    return cs;
}

int largest_island(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int largest = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] and grid[i][j] == 1) {
                int value = dfs(grid, visited, i, j, m, n);
                largest = max(value, largest);
            }
        }
    }
    return largest;
}

int main() {
    vector<vector<int>> grid = {{1, 0, 0, 1, 0},
                                {1, 0, 1, 0, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 0, 1, 1, 0}};

    cout << largest_island(grid) << endl;
}
