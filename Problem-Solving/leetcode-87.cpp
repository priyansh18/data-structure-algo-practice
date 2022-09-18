#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string A, B;
    int dp[35][35][35];
    bool helper(int l1, int r1, int l2, int r2) {
        // base case
        if (A.substr(l1, r1 - l1 + 1) == B.substr(l2, r2 - l2 + 1)) return
        true;

        // cache check
        if (dp[l1][r1][l2] != -1) return dp[l1][r1][l2];

        // computation
        bool ans = false;
        int len = r1 - l1 + 1;
        for (int i = 0; i < len - 1; i++) {
            ans |= helper(l1, l1 + i, l2, l2 + i) and
                   helper(l1 + i + 1, r1, l2 + i + 1, r2);
            ans |= helper(l1, l1 + i, r2 - i, r2) and
                   helper(l1 + i + 1, r1, l2, r2 - i - 1);
        }

        // save and return
        return dp[l1][r1][l2] = ans;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        memset(dp, -1, sizeof(dp));
        A = s1;
        B = s2;
        if (n != m) return false;
        return helper(0, n - 1, 0, m - 1);
    }
};

void solve() {
    Solution s;
    cout << s.isScramble("great", "rgeat");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    for (int i = 0; i < t; i++) {
        solve();
    }
}

