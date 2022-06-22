// Surrounded Regions

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 or j == 0 or i == m - 1 or j == n - 1)
                    if (board[i][j] == 'O') {
                        board[i][j] = 'A';
                        q.push({i, j});
                    }
            }
        }

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newDx = temp.first + dx[k];
                int newDy = temp.second + dy[k];

                if (newDx >= 0 and newDy >= 0 and newDx < m and newDy < n and
                    board[newDx][newDy] == 'O') {
                    board[newDx][newDy] = 'A';
                    q.push({newDx, newDy});
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
                
            }
        }
        
        
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'O', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    s.solve(board);
    for (auto x : board) {
        for (auto y : x) {
            cout << y << ",";
        }
        cout << endl;
    }
}