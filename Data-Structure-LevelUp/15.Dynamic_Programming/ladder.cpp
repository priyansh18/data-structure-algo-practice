#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<int> dp;

int ladder(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (n == 1 or n == 2) {
        return n;
    }

    if (dp[n] != 0) {
        return dp[n];
    }

    int val = 0;
    for (int i = 0; i < K; i++) {
        val += ladder(n - K + i);
    }

    return dp[n] = val;
}

int ladderBottomUp(int n) {
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= K; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }

    return dp[n];
}
int main() {
    cin >> N >> K;
    dp.resize(N + 1);
    dp.assign(N + 1, 0);
    cout << ladder(N) << endl;
    cout << ladderBottomUp(N) << endl;
}