#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int totalSum;
int dp[10010][1000];
vector<vector<int>> v;

int divideArray(int level, int sum) {
    // pruning
    // base case
    if (level == n) {
        if (sum != 0 and sum != totalSum and (sum % (totalSum - sum)) == 0)
            return 1;
        return 0;
    }
    // cache check
    if (dp[level][sum] != -1) return dp[level][sum];
    // computation
    int ans = 0;
    if (divideArray(level + 1, sum + arr[level]))
        ans = 1;
    else if (divideArray(level + 1, sum))
        ans = 1;
    // save and return
    return dp[level][sum] = ans;
}

void printSolution(int level, int sum, vector<int> &res) {
    if (level == n) {
        if (sum != 0 and sum != totalSum and (sum % (totalSum - sum)) == 0)
            v.push_back(res);
        return;
    }

    if (divideArray(level + 1, sum + arr[level])) {
        res.push_back(arr[level]);
        printSolution(level + 1, sum + arr[level], res);
        res.pop_back();
    }

    if (divideArray(level + 1, sum)) {
        printSolution(level + 1, sum, res);
    }
}

void solve() {
    cin >> n;
    arr.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (auto x : arr) totalSum += x;
    vector<int> res;
    printSolution(0, 0, res);

    cout << totalSum << endl;
    for (auto x : v) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int i = 0; i < t; i++) {
        solve();
    }
}