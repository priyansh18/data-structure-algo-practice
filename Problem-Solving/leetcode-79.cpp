//  Word Search

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool foundWord(vector<vector<char>>& board, int i, int j, int m, int n,
                   string word, int l, int z, vector<int> dx, vector<int> dy) {
        if (z == l) return true;
        char val = board[i][j];
        board[i][j] = '[';

        for (int k = 0; k < 4; k++) {
            int newDx = i + dx[k];
            int newDy = j + dy[k];

            if (newDx >= 0 and newDy >= 0 and newDx < m and newDy < n and
                z < l and board[newDx][newDy] == word[z]) {
                bool success = foundWord(board, newDx, newDy, m, n, word, l,
                                         z + 1, dx, dy);
                if (success) return true;
            }
        }

        board[i][j] = val;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};
        int m = board.size();
        int n = board[0].size();
        int l = word.length();
        int i = 0;
        int j = 0;
        int z = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[z]) {
                    bool success =
                        foundWord(board, i, j, m, n, word, l, z + 1, dx, dy);

                    if (success) return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCFSA";
    cout << s.exist(board, word);
}