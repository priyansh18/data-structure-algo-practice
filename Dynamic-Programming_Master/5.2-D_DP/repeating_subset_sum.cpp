#include <bits/stdc++.h>
using namespace std;

vector<int> arr = {2, 8, 4, 10, 12};
int n = arr.size();
int sum = 8;
int count=0;

vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

bool canSumBePossible(int sum, int i, int j) {
    // Base Case
    if (i > j) {
        return false;
    }

    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

    if (sum < 0) {
        return false;
    }

    if (sum == 0) {
        return true;
    }
    // It can work without this include because it is already covered in includeRepeat.
    // Include the number and not repeating
    bool include = canSumBePossible(sum - arr[i], i + 1, j);


    // Include the number and repeating
    bool includeRepeat = canSumBePossible(sum - arr[i], i, j);

    // Exclude the number
    bool exclude = canSumBePossible(sum, i + 1, j);

    return dp[i][sum] = include or exclude or includeRepeat;
}

int main() {
    cout << canSumBePossible(sum, 0, arr.size() - 1);
    
}