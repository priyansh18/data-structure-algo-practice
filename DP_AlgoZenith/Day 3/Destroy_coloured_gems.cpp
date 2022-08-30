#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int dp[105][105];

bool isPalindrome(int l, int r) {
    while (l < r) {
        if (arr[l] != arr[r]) return false;
        l++;
        r--;
    }

    return true;
}

int minSeconds(int l, int r) {
    // Pruning
    if (l > r) return 0;

    // Base case
    if (l == r) return 1;

    // Cache check
    if (dp[l][r] != -1) return dp[l][r];

    // Computation
    if (isPalindrome(l, r)) return dp[l][r] = 1;

    if (arr[l] == arr[r]) {
        return dp[l][r] = minSeconds(l + 1, r - 1);
    }

    int ans = 1e9;
    for (int k = l; k < r; k++) {
        ans = min(ans, minSeconds(l, k) + minSeconds(k + 1, r));
    }
    // Save and return
    return dp[l][r] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << minSeconds(0, n - 1) << endl;
    }

    return 0;
}