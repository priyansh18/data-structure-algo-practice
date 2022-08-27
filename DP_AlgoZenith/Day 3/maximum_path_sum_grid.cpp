#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
int dp[1005][1005];
vector<vector<int>> grid;

int maximumGridSum(int i, int j) {
    // Pruning
    // Base Case
    if (i == n - 1 and j == m - 1) return grid[i][j];
    // Cache Check
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    // Computation
    int ans = -1e9;
    if (i + 1 < n) {
        ans = max(ans, grid[i][j] + maximumGridSum(i + 1, j));
    }
    if (j + 1 < m) {
        ans = max(ans, grid[i][j] + maximumGridSum(i, j + 1));
    }
    // Save and return
    return dp[i][j] = ans;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        grid.resize(n);
        for (int i = 0; i < n; i++) {
            grid[i].resize(m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << maximumGridSum(0, 0) << endl;
    }
    return 0;
}