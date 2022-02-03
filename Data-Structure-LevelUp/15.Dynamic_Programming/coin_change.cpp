#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int coin_change(vector<int> arr, vector<int> &dp, int target) {
    if (target == 0) {
        return 0;
    }
    if (dp[target] != -1) {
        return dp[target];
    }

    int min_value = 1e9;
    for (auto x : arr) {
        if (target - x >= 0) {
            min_value = min(min_value, coin_change(arr, dp, target - x) + 1);
        }
    }

    return dp[target] = min_value;
}

int coin_change_bottom(vector<int> arr, int target) {
    vector<int> dp(target + 1, -1);
    dp[0] = 0;

    for (int i = 1; i < target + 1; i++) {
        int val = 1e9;
        for (auto x : arr) {
            if (i - x >=0) {
                val = min(val, dp[i - x] + 1);
            }
        }

        dp[i] = val;
    }

    for (auto x : dp) {
        cout << x << ",";
    }
    return dp[target];
}

int main() {
    vector<int> arr = {1, 3, 7, 10};
    int target = 15;
    vector<int> dp(target + 1, -1);
    cout << coin_change(arr, dp, target) << endl;

    for (auto x : dp) {
        cout << x << ",";
    }
    cout << endl;
    cout << coin_change_bottom(arr, target) << endl;
}