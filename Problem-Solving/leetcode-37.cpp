// Sudoku Solver

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isSafe(vector<vector<char>> board, int i, int j, int number, int n) {
        // Row & Column Check;
        for (int k = 0; k < n; k++) {
            if (board[i][k] == number or board[k][j] == number) {
                return false;
            }
        }

        int sx = (i / 3) * 3;
        int sy = (i / 3) * 3;
        for (int x = sx; x <= sx + 3; x++) {
            for (int y = sy; y <= sy + 3; y++) {
                if (board[x][y] == number) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board, int i, int j, int n) {
        if (i == n) {
            return true;
        }

        if (j == n) {
            return solveSudokuHelper(board, i + 1, 0, n);
        }

        if (board[i][j] != 0) {
            return solveSudokuHelper(board, i, j + 1, n);
        }

        for (int number = "1"; number <= "9"; number++) {
            if (isSafe(board, i, j, number, n)) {
                board[i][j] = number;
                if (solveSudokuHelper(board, i, j + 1, n)) {
                    return true;
                }
            }
        }

        board[i][j] = ".";
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solveSudokuHelper(board, 0, 0, n);
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {"5", "3", ".", ".", "7", ".", ".", ".", "."},
        {"6", ".", ".", "1", "9", "5", ".", ".", "."},
        {".", "9", "8", ".", ".", ".", ".", "6", "."},
        {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
        {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
        {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
        {".", "6", ".", ".", ".", ".", "2", "8", "."},
        {".", ".", ".", "4", "1", "9", ".", ".", "5"},
        {".", ".", ".", ".", "8", ".", ".", "7", "9"}};

    s.solveSudoku(board);
    int n = board.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ",";
        }
        cout << endl;
    }
}