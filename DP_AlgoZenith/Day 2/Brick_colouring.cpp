#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dp[2001][2001];
const int M = 1e9 + 7;
int brickColouring(int level, int k) {
    // Base Case
    if (k == 0 and level == n) return 1;
    if (k != 0 and level == n) return 0;
    // Caching
    if (dp[level][k] != -1) return dp[level][k];
    long long opt1 = (1LL * (m - 1) * brickColouring(level + 1, k - 1)) % M;
    long long opt2 = brickColouring(level + 1, k);
    // Save and return
    return dp[level][k] = (opt1 + opt2) % M;
}

int main() {
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--) {
        cin >> n >> m >> k;
        int ans = (1LL * m * brickColouring(1, k)) % M;
        cout << ans << endl;
        return 0;
    }
}