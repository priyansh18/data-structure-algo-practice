#include <iostream>
#include <vector>
using namespace std;

int numberOfBSTPossible(int n, vector<int> &dp) {
    if (n == 0 or n == 1) {
        return dp[n] = 1;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = numberOfBSTPossible(i - 1, dp);
        int y = numberOfBSTPossible(n - i, dp);
        ans += x * y;
    }
    return dp[n] = ans;
}

int numberOfBSTPossibleBottomUp(int n) {
    vector<int> dp(n, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= i; j++) {
            ans += (dp[i - j] * dp[j - 1]);
        }
        dp[i] = ans;
    }

    return dp[n];
}

int main() {
    int n = 5;

    vector<int> dp(10, 0);
    cout << numberOfBSTPossible(n, dp) << endl;
    cout << numberOfBSTPossibleBottomUp(n) << endl;
}