#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long countWays(int n, int k) {
        // code here
        long long int m = 1000000007;
        long long int dp[n + 1];
        dp[1] = k;
        dp[2] = k * k;

        for (int i = 3; i <= n; i++) {
            dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % m;
        }

        return dp[n];
    }
};

int main() {
    Solution s;
    int n = 5;
    int k = 2;
    cout << s.countWays(n, k);
}