#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canQueenBeSafe(vector<vector<char>> board, int n, int x, int y) {
    // Column Check
    for (int k = 0; k < x; k++) {
        if (board[k][y] == 'Q') {
            return false;
        }
    }

    // Left Diagonal Check
    int i = x;
    int j = y;
    while (i >= 0 and j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }

    // Right Diagonal Check
    i = x;
    j = y;
    while (i >= 0 and j < n) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool solveNQueen(vector<vector<char>> &board, int n, int i) {
    // Base Case
    if (i == n) {
        printBoard(board, n);
        return true;
    }

    // Recursive Case;
    // Trying to place queen in each row
    for (int j = 0; j < n; j++) {
        // Whether the current position is safe or not
        if (canQueenBeSafe(board, n, i, j)) {
            board[i][j] = 'Q';

            bool success = solveNQueen(board, n, i + 1);
            if (success) return true;

            // BackTracking
            board[i][j] = '.';
        }
    }

    // If exited out of for loop means then queen can't be place anywhere in
    // this row
    return false;
}

int main() {
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    cout << solveNQueen(board, n, 0);
}