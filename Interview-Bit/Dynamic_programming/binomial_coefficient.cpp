#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int nCr(int n, int r) {
        // code here
        if (n < r) return 0;
        if (n - r < r) r = n - r;
        int m = 1000000007;
        vector<int> dp(r + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = min(r, i); j > 0; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % m;
            }
        }

        return dp[r];
    }
};

int main() {
    Solution s;
    int n = 5;
    int r = 2;
    cout << s.nCr(n, r) << endl;
}
