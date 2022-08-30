#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int> nums, int n) {
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        int element = nums[i];
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (element < nums[j]) {
                element = nums[j];
                count++;
            }
        }
        max_count = max(count, max_count);
    }

    return max_count;
}

// Bottom Up
int LIS_DP(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max_value = INT_MIN;
    for (auto x : dp) {
        cout << x << ",";
        max_value = max(x, max_value);
    }

    return max_value;
}

// O(nlogn)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        for (int i = 0;i < n; i++) {
            if(lis.empty() or lis.back() < nums[i]){
                lis.push_back(nums[i]);
            }else{
                auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
                *it = nums[i];
            }
                                                
        }

        return lis.size();
    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    // reverse(nums.begin(),nums.end());
    int n = nums.size();

    cout << LIS_DP(nums) << endl;
}