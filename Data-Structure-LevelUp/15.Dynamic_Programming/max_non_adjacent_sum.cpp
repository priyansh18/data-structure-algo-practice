#include <iostream>
#include <vector>
using namespace std;

int maximumNonAdjancentSum(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n, -1);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n-1];
}



int main() {
    vector<int> nums = {6, 10, 12, 7, 9, 14};
    cout << maximumNonAdjancentSum(nums);
}