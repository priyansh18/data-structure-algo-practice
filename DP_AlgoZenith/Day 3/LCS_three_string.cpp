#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;

int dp[105][105][105];

int LCS(int i, int j, int k) {
    // pruning

    // base case
    if (i == s1.length() or j == s2.length() or k == s3.length()) return 0;
    // cache check
    if (dp[i][j][k] != -1) return dp[i][j][k];
    // computing
    int ans = 0;
    ans = max(ans, LCS(i + 1, j, k));
    ans = max(ans, LCS(i, j + 1, k));
    ans = max(ans, LCS(i, j, k + 1));
    if (s1[i] == s2[j] && s2[j] == s3[k])
        ans = max(ans, 1 + LCS(i + 1, j + 1, k + 1));

    // save and return
    return dp[i][j][k] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s1 >> s2 >> s3;
        memset(dp, -1, sizeof(dp));
        cout << LCS(0, 0, 0) << endl;
    }
}