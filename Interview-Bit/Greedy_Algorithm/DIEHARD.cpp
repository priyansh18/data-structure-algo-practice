#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001][4];
int survivalTime(int i, int j, int s) {
    if (i <= 0 or j <= 0) {
        return 0;
    }

    if (dp[i][j][s] != -1) {
        return dp[i][j][s];
    }

    if (s == 0) {
        return dp[i][j][s] = max({survivalTime(i + 3, j + 2, 1),
                                  survivalTime(i - 5, j - 10, 2),
                                  survivalTime(i - 20, j + 5, 3)});
    }
    if (s == 1) {
        return dp[i][j][s] = max(survivalTime(i - 5, j - 10, 2),
                                 survivalTime(i - 20, j + 5, 3)) +
                             1;
    }
    if (s == 2) {
        return dp[i][j][s] = max(survivalTime(i + 3, j + 2, 1),
                                 survivalTime(i - 20, j + 5, 3)) +
                             1;
    } else {
        return dp[i][j][s] = max(survivalTime(i + 3, j + 2, 1),
                                 survivalTime(i - 5, j - 10, 2)) +
                             1;
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        /* code */
        int x;
        int y;
        cin >> x >> y;
        memset(dp, -1, sizeof(dp));
        cout << survivalTime(x, y, 0) << endl;
    }
}