#include <bits/stdc++.h>
using namespace std;
// #define int long long

int n;
string str;
vector<int> arr;
long long dp[100100][5];
string t = "hard";

long long minCost(int level, int match) {
    // pruning 
    if (match >= 4) return 1e18;
    // base case
    if (level == n) return 0;
    // cache check
    if (dp[level][match] != -1) return dp[level][match];
    // computation
    long long ans = 1e18;
    if (str[level] != t[match]) {
        ans = min(minCost(level + 1, match),
                  arr[level] + minCost(level + 1, match));
    } else {
        ans = min(minCost(level + 1, match + 1),
                  arr[level] + minCost(level + 1, match));
    }
    return dp[level][match] = ans;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> str;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        memset(dp, -1, sizeof(dp));
        cout << minCost(0, 0) << endl;
    }
}