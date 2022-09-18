#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isEqual(string s, string p, int n, int m) {
        // pruning

        // base case

        // when both string completed.
        if (n < 0 and m < 0) return true;

        // when string is finished but pattern remains if it contains all stars
        // then true else false;
        if (n < 0) {
            for (int i = 0; i < m; i++) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }
        // when patten is finished but string doesn't.
        if (m < 0) return false;

        // cache check

        // computation
        bool ans = false;
        if (p[m] == '*') {
            int x = n;
            while (x >= 0) {
                ans |= isEqual(s, p, n - x, m - 1);
                x--;
            }
        } else if (p[m] == '.') {
            ans |= isEqual(s, p, n - 1, m - 1);
        } else {
            if (s[n] != p[m]) ans |= false;
        }

        // save and return
        return ans;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return isEqual(s, p, n - 1, m - 1);
    }
};

void solve() {
    Solution ss;
    string s = "bab";
    string p = "b*a";
    cout << ss.isMatch(s, p);
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