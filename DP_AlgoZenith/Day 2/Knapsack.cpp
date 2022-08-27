#include <bits/stdc++.h>
using namespace std;

vector<int> weight;
vector<int> profit;

int dp[21][101];

int maximumProfit(int N, int W) {
    // Base Case
    if (N == 0 or W == 0) {
        return 0;
    }

    // Caching
    if (dp[N][W] != -1) return dp[N][W];
    int opt1 = 0;
    int opt2 = 0;
    // Excluding current item
    opt1 = maximumProfit(N - 1, W);

    // Including current item
    if (W - weight[N - 1] >= 0) {
        opt2 = profit[N - 1] + maximumProfit(N - 1, W - weight[N - 1]);
    }
    // Save and return
    return dp[N][W] = max(opt1, opt2);
}

int main() {
    int N, W;
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        weight.push_back(a);
        profit.push_back(b);
    }
    memset(dp, -1, sizeof(dp));
    cout << maximumProfit(N, W) << endl;
}