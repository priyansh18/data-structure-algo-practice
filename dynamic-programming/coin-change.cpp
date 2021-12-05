#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Bottom Up Approach
int minNumberOfCoinsForChange(int m, vector<int> denoms) {
    vector<int> dp(m + 1, INT8_MAX);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int c : denoms) {
            if (i - c >= 0 and dp[i - c] != INT8_MAX) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[m] == INT8_MAX ? -1 : dp[m];
}

int main() {
    vector<int> denoms = {1, 5, 7, 10};
    int n;
    cin >> n;
    cout << minNumberOfCoinsForChange(n, denoms);
}