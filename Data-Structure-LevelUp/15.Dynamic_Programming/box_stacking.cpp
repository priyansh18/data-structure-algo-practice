#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

bool Compare(vector<int> b1, vector<int> b2) { return b1[2] < b2[2]; }

bool canPlace(vector<int> b1, vector<int> b2) {
    if (b1[1] < b2[1] and b1[0] < b2[0]) {
        return true;
    }
    return false;
}

int boxStacking(vector<vector<int>> cuboids) {
    // Sorting Based on height
    sort(cuboids.begin(), cuboids.end(), Compare);

    // Dp
    int n = cuboids.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = cuboids[i][2];
    }

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (canPlace(cuboids[j], cuboids[i])) {
                int current_height = cuboids[i][2];
                if (dp[j] + current_height > dp[i]) {
                    dp[i] = dp[j] + current_height;
                }
            }
        }
    }
    int max_val = INT_MIN;
    for (auto x : dp) {
        // cout << x << ",";
        max_val = max(max_val, x);
    }

    return max_val;
}

int main() {
    vector<vector<int>> cuboids = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8},
                                   {2, 3, 4}, {2, 2, 1}, {4, 4, 5}};
    int height = boxStacking(cuboids);
    cout << height << endl;
}