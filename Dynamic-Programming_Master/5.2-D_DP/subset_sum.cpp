#include <bits/stdc++.h>
using namespace std;

vector<int> arr = {2, 7, 4, 5, 19};
int n = arr.size();
int sum = 22;

vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

bool canSumBePossible(int sum, int i, int j) {
    // Base Case
    if (i > j) {
        return false;
    }

    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

    if (sum == 0) {
        return true;
    }

    // Include the number
    bool include = canSumBePossible(sum - arr[i], i + 1, j);

    // Exclude the number
    bool exclude = canSumBePossible(sum, i + 1, j);

    return dp[i][sum] = include or exclude;
}

int main() { cout << canSumBePossible(sum, 0, arr.size() - 1); }