#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

long long maximumProduct() {
    vector<pair<int, int>> dp(n);
    dp[0] = {arr[0], arr[0]};
    int maxAns = arr[0];
    for (int i = 1; i < n; i++) {
        int mx = LONG_LONG_MAX(
            {arr[i] * (dp[i - 1].first), arr[i] * (dp[i - 1].first), arr[i]});
        int mn = min(
            {arr[i] * (dp[i - 1].first), arr[i] * (dp[i - 1].first), arr[i]});
        dp[i] = {mx, mn};
        maxAns = max({maxAns, mx, mn});
    }

    return maxAns;
}

int maximumProduct() {
    int maxV = arr[0];
    int minV = arr[0];
    int maxEl = arr[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < 0) {
            swap(maxV, minV);
        }
        maxV = max(arr[i], arr[i] * maxV);
        minV = min(arr[i], arr[i] * minV);
        maxEl = max(maxEl, maxV);
    }

    return maxEl;
}

void solve() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maximumProduct() << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}