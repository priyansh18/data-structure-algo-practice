#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> board;

void printSolution() {
    for (auto x : board) {
        for (auto c : x) {
            cout << c << " ";
        }
        cout << endl;
    }
}

bool canPlaceQueen(int x, int y) {
    // Col Check
    for (int k = 0; k < x; k++) {
        if (board[k][y] == 'Q') {
            return false;
        }
    }

    // Left Diagonal Check
    int _x = x;
    int _y = y;

    while (_x >= 0 and _y >= 0) {
        if (board[_x][_y] == 'Q') {
            return false;
        }
        _x--;
        _y--;
    }

    // Right Diagonal Check
    _x = x;
    _y = y;

    while (_x >= 0 and _y < n) {
        if (board[_x][_y] == 'Q') {
            return false;
        }
        _x--;
        _y++;
    }

    // Knight Check
    _x = x;
    _y = y;
    vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int k = 0; k < 8; k++) {
        int newX = _x + dx[k];
        int newY = _y + dy[k];
        if (newX >= 0 and newX < n and newY >= 0 and newY < n and
            board[newX][newY] == 'Q') {
            return false;
        }
    }

    return true;
}

int noWaysToPlaceQueens(int i) {
    if (i == n) {
        printSolution();
        cout << endl;
        return 1;
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if (canPlaceQueen(i, j)) {
            char temp = board[i][j];
            board[i][j] = 'Q';
            ans += noWaysToPlaceQueens(i + 1);
            board[i][j] = temp;
        }
    }

    return ans;
}

int main() {
    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; ++i) board[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    for (auto x : board) {
        for (auto c : x) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << noWaysToPlaceQueens(0) << endl;
}