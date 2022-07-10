#include <bits/stdc++.h>
using namespace std;

int dp[10][10][10][10][10];
int maximumGain(vector<int> &x, vector<int> &y, int i, int j, int m, int n,
                int k) {
    if (k == 0) return 0;
    if ((i > m) or (j > n) or (m < 0) or (n < 0)) return 0;

    int ans = 0;
    int opt1 = 0;
    int opt2 = 0;
    int opt3 = 0;
    int opt4 = 0;

    if (dp[i][j][m][n][k] != -1) return dp[i][j][m][n][k];

    if (i + 1 <= m) {
        opt1 = x[i] + maximumGain(x, y, i + 1, j, m, n, k - 1);
    }
    if (j + 1 <= n) {
        opt2 = y[j] + maximumGain(x, y, i, j + 1, m, n, k - 1);
    }
    if (m - 1 >= 0) {
        opt3 = x[m] + maximumGain(x, y, i, j, m - 1, n, k - 1);
    }
    if (n - 1 >= 0) {
        opt4 = y[n] + maximumGain(x, y, i, j, m, n - 1, k - 1);
    }

    return dp[i][j][m][n][k] = max({opt1, opt2, opt3, opt4});
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        vector<int> arr1;
        for (int i = 0; i < x; i++) {
            int a;
            cin >> a;
            arr1.push_back(a);
        }
        int y;
        cin >> y;
        vector<int> arr2;
        for (int i = 0; i < y; i++) {
            int b;
            cin >> b;
            arr2.push_back(b);
        }
        int k;
        cin >> k;
        memset(dp, -1, sizeof(dp));
        cout << "Case #" << i + 1 << ": "
             << maximumGain(arr1, arr2, 0, 0, x - 1, y - 1, k) << endl;
    }
}