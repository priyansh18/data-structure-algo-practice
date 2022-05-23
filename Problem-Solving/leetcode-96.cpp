// Unique binary search trees;

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numTreesHelper(vector<int> &dp, int n) {
        if (n == 0) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += numTreesHelper(dp,n - i) * numTreesHelper(dp,i - 1);
        }

        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return numTreesHelper(dp, n);
    }
};

int main() {
    Solution s;
    int n = 4;
    cout << s.numTrees(n);
}