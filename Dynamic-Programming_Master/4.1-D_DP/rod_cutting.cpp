#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> arr, int n, vector<int> dp) {
    if (n <= 0) {
        return 0;
    }

    if (dp[n] != -1) return dp[n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i] + maxProfit(arr, n - i - 1,dp));
    }

    return dp[n] = ans;
}

int main() {
    int n = 8;
    vector<int> arr = {1, 3, 4, 5, 7, 9, 10, 11};
    vector<int> dp(n + 1, -1);
    cout << maxProfit(arr, n, dp);
}