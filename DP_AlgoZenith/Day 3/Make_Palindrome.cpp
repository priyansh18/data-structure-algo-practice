#include <bits/stdc++.h>
using namespace std;

string s;
int dp[1005][1005];

int minCharPalindrome(int l, int r) {
    // Pruning

    // Base Case
    if (l > r) return 0;

    // Cache check
    if (dp[l][r] != -1) return dp[l][r];

    // Computation
    int ans = 1e9;
    if (s[l] == s[r])
        ans = min(ans, minCharPalindrome(l + 1, r - 1));
    else
        ans = min({ans, 1 + minCharPalindrome(l + 1, r),
                   1 + minCharPalindrome(l, r - 1)});

    // Save and return
    return dp[l][r] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        cout << minCharPalindrome(0, s.length() - 1) << endl;
    }

    return 0;
}