#include <bits/stdc++.h>
using namespace std;
char board[8][8];
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

    while (_x >= 0 and _y < 8) {
        if (board[_x][_y] == 'Q') {
            return false;
        }
        _x--;
        _y++;
    }

    return true;
}

int noWaysToPlaceQueen(int i) {
    if (i == 8) {
        return 1;
    }
    int ans = 0;
    for (int j = 0; j < 8; j++) {
        if (canPlaceQueen(i, j) and board[i][j] != '*') {
            char temp = board[i][j];
            board[i][j] = 'Q';
            ans += noWaysToPlaceQueen(i + 1);
            board[i][j] = temp;
        }
    }

    return ans;
}
int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    cout << noWaysToPlaceQueen(0) << endl;
}