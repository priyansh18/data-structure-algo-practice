// Snake & Ladders

#include <bits/stdc++.h>
using namespace std;

// class Solution {
//    public:
//     int snakesAndLadders(vector<vector<int>>& board) {
//         int n = board.size();
//         queue<pair<int, int>> q;
//         vector<vector<int>> visited(n, vector<int>(n, 0));
//         vector<vector<int>> dist(n, vector<int>(n, 0));
//         q.push({n - 1, 0});
//         visited[n - 1][0] = 1;

//         while (!q.empty()) {
//             auto temp = q.front();
//             q.pop();
//             for (int k = 1; k <= 6; k++) {
//                 int newX = temp.first + k;
//                 int newY = temp.second + k;

//                 if (newX >= 0 and newY >= 0 and newX < n and newY < n and
//                     !visited[newX][newY]) {
//                     if (board[newX][newY] == -1) {
//                         dist[newX][newY] = dist[temp.first][temp.second] + 1;
//                         visited[newX][newY] = 1;
//                         q.push({newX, newY});
//                     } else {
//                         int newXX = (board[newX][newY] % n) - 1;
//                         int newYY = (board[newX][newY] % n) - 1;
//                         dist[newXX][newYY] = dist[temp.first][temp.second] +
//                         1; visited[newX][newY] = 1; visited[newXX][newYY] =
//                         1; q.push({newXX, newYY});
//                     }
//                 }
//             }
//         }

//         for (auto x : dist) {
//             for (auto y : x) {
//                 cout << y << ",";
//             }
//             cout << endl;
//         }

//         return 0;
//     }
// };

// class Solution {
//    public:
//     int snakesAndLadders(vector<vector<int>>& board) {
//         int n = board.size();
//         queue<int> q;
//         vector<vector<int>> visited(n, vector<int>(n, 0));
//         vector<vector<int>> dist(n, vector<int>(n, 0));
//         q.push(1);
//         while (!q.empty()) {
//             int temp = q.front();
//             q.pop();
//             int xCor = temp % n - 1;
//             int yCor = temp % n - 1;

//             for (int i = 1; i <= 6; i++) {
//                 int newX = xCor + i;
//                 int newY = yCor + i;

//                 if (newX >= 0 and newY >= 0 and newX < n and newY < n and
//                     !visited[newX][newY]) {
//                     if (board[newX][newY] == -1) {
//                         visited[newX][newY] = 1;
//                         q.push(board[n])
//                     }
//                 }
//             }
//         }
//     }
// };

class Solution {
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        reverse(board.begin(), board.end());

        vector<int> newBoard(n * n);
        int k = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    newBoard[k++] = board[i][j] == -1 ? -1 : board[i][j] - 1;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    newBoard[k++] = board[i][j] == -1 ? -1 : board[i][j] - 1;
                }
            }
        }

        queue<int> q;
        q.push(0);
        vector<int> visited(n * n, 0);
        vector<int> dist(n * n, -1);
        visited[0] = 1;
        dist[0] = 0;

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            for (int dice = 1; dice <= 6; dice++) {
                if (temp + dice < n * n) {
                    int newVal = newBoard[temp + dice] == -1
                                     ? temp + dice
                                     : newBoard[temp + dice];

                    if (!visited[newVal]) {
                        visited[newVal] = 1;
                        dist[newVal] = dist[temp] + 1;
                        q.push(newVal);
                    }
                }
            }
        }
        return dist[n * n - 1] == -1 ? -1 : dist[n * n - 1];
    }
   public:
};
int main() {
    Solution s;
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
    cout << s.snakesAndLadders(board) << endl;
}