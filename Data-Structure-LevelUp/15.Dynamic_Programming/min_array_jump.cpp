#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int minimumArrayJump(vector<int> arr, int i, int n) {
    if (i == n) {
        return 0;
    }
    if (i > n) {
        return 1e9;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    int min_value = 1e9;
    for (int j = i + 1; j <= i + arr[i]; j++) {
        min_value = min(min_value, minimumArrayJump(arr, j, n) + 1);
    }

    return dp[i] = min_value;
}

int mininmumArrayJump_Bp(vector<int> arr, int v) {
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int min_value = 1e9;
        for (int j = i + 1; j <= i + arr[i]; j++) {
          
            if (j <= n) {
                dp[i] = min(min_value, dp[j] + 1);
            }
        }
    }

    for (auto x : dp) {
        cout << x << ",";
    }
    cout<<endl;

    return dp[v];
}

int main() {
    vector<int> arr = {2, 3, 1, 1, 4};
    int i = 0;
    dp.resize(arr.size() + 1);
    dp.assign(arr.size() + 1, -1);

    cout << minimumArrayJump(arr, i, arr.size() - 1) << endl;
    cout << mininmumArrayJump_Bp(arr, i)<<endl;
}
