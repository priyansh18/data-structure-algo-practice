// Liongest Bitonic Subsequence

#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int> nums) {
    int n = nums.size();
    vector<int> left(n);
    vector<int> right(n);

    left[0] = 1;
    for (int i = 1; i < n; i++) {
        int x = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                x = max(x, left[j] + 1);
            }
        }
        left[i] = x;
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        int x = 1;
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                x = max(x, right[j] + 1);
            }
        }
        right[i] = x;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, right[i] + left[i] - 1);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 4, 3, 5, 2, 6};
    cout << longestSubsequence(nums) << endl;
}