#include <bits/stdc++.h>
using namespace std;


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

int noOfWaysToSolveNQueen(vector<vector<char>> &board, int n, int i) {
    // Base Case
    if (i == n) {
        return 1;
    }

    // Recursive Case;
    // Trying to place queen in each row
    int ways = 0;
    for (int j = 0; j < n; j++) {
        // Whether the current position is safe or not
        if (canQueenBeSafe(board, n, i, j)) {
            board[i][j] = 'Q';
            ways += noOfWaysToSolveNQueen(board, n, i + 1);
            // BackTracking
            board[i][j] = '.';
        }
    }

    // If exited out of for loop means then queen can't be place anywhere in
    // this row
    return ways;
}

int main() {
    int n = 8;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    cout << noOfWaysToSolveNQueen(board, n, 0);
}