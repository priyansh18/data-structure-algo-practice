// All Possible N-Queens.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void printBoard(vector<vector<string>> &result, vector<vector<char>> board,
                    int n) {
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = 0; j < n; j++) {
                str += board[i][j];
            }
            res.push_back(str);
        }

        result.push_back(res);
    }

    bool canQueenBeSafe(vector<vector<char>> board, int x, int y, int n) {
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

    void solveNQueensHelper(vector<vector<string>> &result,
                            vector<vector<char>> &board, int n, int i) {
        if (i == n) {
            printBoard(result, board, n);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (canQueenBeSafe(board, i, j, n)) {
                board[i][j] = 'Q';
                solveNQueensHelper(result, board, n, i+1);
                board[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> result;
        solveNQueensHelper(result, board, n, 0);
        return result;
    }
};

int main() {
    Solution s;
    int n = 4;
    vector<vector<string>> result = s.solveNQueens(n);
    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}