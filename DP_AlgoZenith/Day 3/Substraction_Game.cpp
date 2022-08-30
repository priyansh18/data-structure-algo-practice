#include <bits/stdc++.h>
using namespace std;

int dp[200010];

int substractionGame(int n) {
    if (n == 0) return 0;

    if (dp[n] != -1) return dp[n];

    int ans = 0;
    for (int m = 0; (1 << m) <= n; m++) {
        if (substractionGame(n - (1 << m)) == 0) {
            ans = 1;
            break;
        }
    }

    return dp[n] = ans;
}

int main() {
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--) {
        int n;
        cin >> n;
        // for (int i = 0; i < n; i++) {
        //     cout << i << " : " << substractionGame(i)<<endl;
        // }
        substractionGame(n) ? cout << "Vivek" << endl
                            : cout << "Abhishek" << endl;
    }
}