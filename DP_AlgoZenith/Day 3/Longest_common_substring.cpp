#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1005][1005];
int longestCommonSubstring() {
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        memset(dp, -1, sizeof(dp));
        cout << longestCommonSubstring() << endl;
    }
}