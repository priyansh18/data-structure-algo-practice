// Game of Life

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int livesOrDie(vector<vector<int>> board, int i, int j, int m, int n) {
        int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

        int count = 0;
        for (int k = 0; k < 8; k++) {
            int newDx = i + dx[k];
            int newDy = j + dy[k];

            if (newDx >= 0 and newDy >= 0 and newDx < m and newDy < n and
                (board[newDx][newDy] == 1 or board[newDx][newDy] == -2)) {
                count++;
              
            }
        }

        if (board[i][j] == 0) {
            if (count == 3) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (count < 2) {
                return 0;
            } else if (count == 2 or count == 3) {
                return 1;
            } else if (count > 3) {
                return 0;
            }
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> mat(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int retVal = livesOrDie(board, i, j, m, n);
                if (board[i][j] == 0) {
                    if (retVal == 1) board[i][j] = -1;  // orignally 0
                } else {
                    if (retVal == 0) board[i][j] = -2;  // orignally 1
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 1;
                } else if (board[i][j] == -2) {
                    board[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    s.gameOfLife(board);
}