#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

void setBitsHelper(vector<int> &result, int n) {
    dp[0] = 0;
    result.push_back(dp[0]);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i / 2] + (i % 2);
        result.push_back(dp[i]);
    }
}

vector<int> setBits(int n) {
    vector<int> result;
    setBitsHelper(result, n);
    return result;
}

int main() {
    int n = 10;
    dp.resize(n + 1, -1);
    vector<int> result = setBits(n);
    for (auto x : result) {
        cout << x << ",";
    }
}