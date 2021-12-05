#include <iostream>
using namespace std;

int wines(int dp[][10], int prices[], int L, int R, int y) {
    if (L > R) {
        return 0;
    }
    if (dp[L][R] != 0) {
        return dp[L][R];
    }
    // Rec case
    int pick_left = prices[L] * y + wines(dp, prices, L + 1, R, y + 1);
    int pick_right = prices[R] * y + wines(dp, prices, L, R - 1, y + 1);

    return dp[L][R] = max(pick_left, pick_right);
}

int main() {
    int a[] = {2, 3, 5, 1, 4};
    int n = 5;
    int dp[10][10] = {0};
    cout << wines(dp, a, 0, n - 1, 1) << endl;
}