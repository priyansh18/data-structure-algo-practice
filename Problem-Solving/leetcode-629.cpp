// K Inverse Pairs

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int dp[1001][1001];
    int helper(int n, int k) {
        if (n == 0) return 0;
        if (k == 0) return 1;
        int ans = 0;
        if (dp[n][k] != -1) return dp[n][k];
        for (int i = 0; i <= min(k, n - 1); i++) {
            ans = (ans + helper(n - 1, k - i)) % (1000000007);
        }

        return dp[n][k] = ans;
    }

    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(n, k);
    }
};

int main() {
    Solution s;
    int n = 3;
    int k = 2;
    cout << s.kInversePairs(n, k) << endl;
}