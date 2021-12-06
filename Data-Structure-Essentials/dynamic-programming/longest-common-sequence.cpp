#include <iostream>
#include <vector>
using namespace std;

int lcs(vector<int> a) {
    int n = a.size();
    vector<int> dp(n, 1);
    int lcs = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    for (int x : dp) {
        lcs = max(lcs, x);
    }

    return lcs;
}

int main() {
    vector<int> arr = {50, 4, 10, 8, 30, 100};
    cout << "Length of Longest Common Subsequence is : " << lcs(arr) << endl;
}