#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int noOfWays(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (dp[n] != -1) return dp[n];
    return dp[n] = noOfWays(n - 1) + noOfWays(n - 2);
}

int main() {
    int n = 3;
    dp.resize(n + 1, -1);
    cout << noOfWays(n) << endl;
}