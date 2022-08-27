#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];
vector<vector<int>> v;
#define ll long long

int rec(vector<int>& arr, int n, int level, int left) {
    // Pruning
    if (left < 0) return 0;

    // Base Case
    if (level == n) {
        if (left == 0)
            return 1;
        else
            return 0;
    }
    // Caching

    if (dp[level][left] != -1) return dp[level][left];
    int ans = 0;
    if (rec(arr, n, level + 1, left - arr[level])) {
        ans = 1;
    } else if (rec(arr, n, level + 1, left)) {
        ans = 1;
    }
    return dp[level][left] = ans;
}

void printSet(vector<int>& arr, int n, int level, int left, vector<int>& temp) {
    if (level == n) {
        v.push_back(temp);
        return;
    } else if (rec(arr, n, level + 1, left - arr[level])) {
        temp.push_back(level);
        printSet(arr, n, level + 1, left - arr[level], temp);
    } else if (rec(arr, n, level + 1, left)) {
        printSet(arr, n, level + 1, left, temp);
    }
}

vector<vector<int>> subset_queries(vector<int>& arr, vector<int>& queries) {
    int n = arr.size();
    memset(dp, -1, sizeof(dp));
    for (auto x:queries) {
        if (rec(arr, n, 0, x)) {
            vector<int> temp;
            printSet(arr, n, 0, x, temp);
        } else {
            v.push_back({-1});
        }
    }
    return v;
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> queries = {7, 16, 3};
    vector<vector<int>> result = subset_queries(arr, queries);
    for (auto x : result) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
    return 0;
}