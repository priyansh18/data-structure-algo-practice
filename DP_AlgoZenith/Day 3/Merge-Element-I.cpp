#include <bits/stdc++.h>
using namespace std;

int arr[10001];
pair<int, int> dp[105][105];

pair<int, int> minMergeCost(int l, int r) {
    // pruning
    if (l > r) return {0, 0};
    // base case
    if (l == r) return {arr[l], 0};
    // cache check
    if (dp[l][r].first != -1) return dp[l][r];
    // computing
    int ans = 1e9;
    int mergeElement = 0;
    int mergeCost = 0;
    for (int i = l; i < r; i++) {
        auto leftPair = minMergeCost(l, i);
        auto rightPair = minMergeCost(i + 1, r);
        mergeElement = (leftPair.first + rightPair.first) % 100;
        mergeCost = leftPair.second + rightPair.second +
                    leftPair.first * rightPair.first;
        ans = min(ans, mergeCost);
    }

    // save and return
    return dp[l][r] = {mergeElement, ans};
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = {-1, -1};
        }
    }
    cout << minMergeCost(0, n - 1).second << endl;
    return 0;
}
