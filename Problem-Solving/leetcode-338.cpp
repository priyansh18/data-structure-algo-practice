#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> result;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        result.push_back(dp[0]);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i / 2] + (i % 2);
            result.push_back(dp[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    int n = 5;
    vector<int> result = s.countBits(n);
    for (auto x : result) {
        cout << x << ",";
    }
}