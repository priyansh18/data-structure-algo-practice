#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
int dp[1005][1005];

const int M = 1e9 + 7;

int noWays(int i, int j) {
    // pruning
    if (grid[i][j] == 1) return 0;
    // base case
    if (i == n - 1 and j == m - 1) return 1;
    // cache check
    if (dp[i][j] != -1) return dp[i][j];
    // computing
    long long ways = 0;
    if (i + 1 < n) ways += noWays(i + 1, j) ;
    if (j + 1 < m) ways += noWays(i, j + 1);
    // save and return
    return dp[i][j] = ways % M;
}

int main() {
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
           		dp[i][j] = -1;
            }
        }
        
        // memset(dp, -1, sizeof(dp));
        cout << noWays(0, 0) << endl;
    }

    return 0;
}