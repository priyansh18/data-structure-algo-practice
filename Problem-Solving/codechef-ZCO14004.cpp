#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    vector<int> dp(n + 1);
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2];

    for (int i = 3; i < n; i++) {
        dp[i] = min(dp[i - 1], min(dp[i - 2], dp[i - 3])) + arr[i];
    }

    return sum - min(dp[n - 1], min(dp[n - 2], dp[n - 3]));
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maximumProfit(arr, n);
}