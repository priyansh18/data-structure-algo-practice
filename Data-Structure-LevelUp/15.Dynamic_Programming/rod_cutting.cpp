#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int cutting_rods(vector<int> price, int n, vector<int> &dp) {
    if (n <= 0) {
        return 0;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        max_val = max(max_val, price[i] + cutting_rods(price, n - i - 1, dp));
    }

    return dp[n] = max_val;
}

int cutting_rods_bp(vector<int> price, int n) {
    vector<int> dp(n + 1,-1);
    dp[0] = 0;

    for (int i = 1; i < n + 1; i++) {
        int ans = INT_MIN;
        for (int j = 0; j < i; j++) {
            int current_ans = price[j] + dp[i - j - 1];
            ans = max(ans, current_ans);
        }
        dp[i] = ans;
    }

    return dp[n];
}

int main() {
    int n = 8;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> dp(n + 1, -1);
    cout << cutting_rods(price, n, dp) << endl;
    for (auto x : dp) {
        cout << x << ",";
    }
    cout<<endl;
    cout << cutting_rods_bp(price, n) << endl;

}