#include <bits/stdc++.h>
using namespace std;

void print_board(vector<vector<int>> sudoku,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sudoku[i][j] << ",";
        }
        cout << endl;
    }
}

bool canNumberBePlaced(vector<vector<int>> sudoku, int i, int j, int number,
                       int n) {
    // Check for row & Column
    for (int k = 0; k < n; k++) {
        if (sudoku[k][j] == number or sudoku[i][k] == number) {
            return false;
        }
    }

    // Check For Subgrid.
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;

    for (int x = sx; x < sx + 3; x++) {
        for (int y = sy; y < sy + 3; y++) {
            if (sudoku[x][y] == number) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku_solver(vector<vector<int>>& sudoku, int i, int j, int n) {
    if (i == n) {
        print_board(sudoku, n);
        return true;
    }

    if (j == n) {
        return sudoku_solver(sudoku, i + 1, 0, n);
    }
    // Skipping the prefilled cell.
    if (sudoku[i][j] != 0) {
        return sudoku_solver(sudoku, i, j + 1, n);
    }

    for (int no = 1; no <= n; no++) {
        if (canNumberBePlaced(sudoku, i, j, no, n)) {
            sudoku[i][j] = no;
            bool success = sudoku_solver(sudoku, i, j + 1, n);
            if (success) {
                return true;
            }
        }
    }

    sudoku[i][j] = 0;
    return false;
}

int main() {
    vector<vector<int>> sudoku =
    { {5, 3, 0, 0, 7, 0, 0, 0, 0},
      {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0},
      {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1},
      {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0},
      {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 9} };
    cout << sudoku_solver(sudoku, 0, 0, 9);
}