#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
int n;
int dp[100006][5];

long long countBinaryStrings(int level, int match) {
    // pruning
    if (match == 4) return 0;
    // base case
    if (level == n) return 1;
    // cache check
    if (dp[level][match] != -1) return dp[level][match];
    // computation
    long long ans = 0;
    if (match == 0) {
        ans = (countBinaryStrings(level + 1, 0) % M +
               countBinaryStrings(level + 1, 1) % M) %
              M;
    } else if (match == 1) {
        ans = (countBinaryStrings(level + 1, 2) % M +
               countBinaryStrings(level + 1, 1) % M) %
              M;
    } else if (match == 2) {
        ans = (countBinaryStrings(level + 1, 0) % M +
               countBinaryStrings(level + 1, 3) % M) %
              M;
    } else if (match == 3) {
        ans = (countBinaryStrings(level + 1, 2) % M +
               countBinaryStrings(level + 1, 4) % M) %
              M;
    }
    // save and return
    return dp[level][match] = ans % M;
}

void solve() {
    cin >> n;
    cout << countBinaryStrings(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}