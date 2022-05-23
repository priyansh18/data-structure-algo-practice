#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ",";
        }
        cout << endl;
    }
}

bool canGoUp(vector<vector<int>> grid, int x, int y,int n) {
    if (x >= 0 and x < n) {
        if (grid[x][y] == 1) {
            return true;
        }
    }

    return false;
}

bool canGoDown(vector<vector<int>> grid, int x, int y,int n) {
    if (x >= 0 and x < n) {
        if (grid[x][y] == 1) {
            return true;
        }
    }

    return false;
}

bool canGoLeft(vector<vector<int>> grid, int x, int y,int n) {
    if (y >= 0 and y < n) {
        if (grid[x][y] == 1) {
            return true;
        }
    }

    return false;
}

bool canGoRight(vector<vector<int>> grid, int x, int y,int n) {
    if (y >= 0 and y < n) {
        if (grid[x][y] == 1) {
            return true;
        }
    }

    return false;
}

bool ratInMaze(vector<vector<int>> &grid, int i, int j, int n) {
    if (i == n - 1 and j == n - 1) {
        grid[i][j] = 2;
        printSolution(grid, n);
        return true;
    }

    if (canGoUp(grid, i - 1, j, n)) {
        grid[i][j] = 2;
        if (ratInMaze(grid, i - 1, j, n)) return true;
        grid[i][j] = 1;
    }
    if (canGoDown(grid, i + 1, j, n)) {
        grid[i][j] = 2;
        if(ratInMaze(grid, i + 1, j, n)) return true;
        grid[i][j] = 1;
    }
    if (canGoLeft(grid, i, j - 1, n)) {
        grid[i][j] = 2;
        if(ratInMaze(grid, i, j - 1, n)) return true;
        grid[i][j] = 1;
    }
    if (canGoRight(grid, i, j + 1, n)) {
        grid[i][j] = 2;
        if(ratInMaze(grid, i, j + 1, n)) return true;
        grid[i][j] = 1;
    }

    return false;
}

int main() {
    vector<vector<int>> grid = {{1, 0, 1, 1, 1},
                                {1, 1, 1, 0, 1},
                                {1, 0, 0, 1, 1},
                                {1, 0, 0, 1, 0},
                                {1, 0, 0, 1, 1}};

    ratInMaze(grid, 0, 0, grid.size());
}