// Product of Array Except Self

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> prefixMultipleLeft(n);
        prefixMultipleLeft[0] = 1;
        vector<int> prefixMultipleRight(n);
        prefixMultipleRight[n - 1] = 1;

        for (int i = 1; i < n; i++) {
            prefixMultipleLeft[i] = prefixMultipleLeft[i - 1] * nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--) {
            prefixMultipleRight[j] = prefixMultipleRight[j + 1] * nums[j + 1];
        }

        for (auto x : prefixMultipleLeft) cout << x << ",";
        cout << endl;
        for (auto x : prefixMultipleRight) cout << x << ",";
        cout << endl;

        for (int i = 0; i < n; i++) {
            result[i] = prefixMultipleLeft[i] * prefixMultipleRight[i];
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = s.productExceptSelf(nums);
    for (auto c : result) {
        cout << c << ",";
    }
    cout << endl;
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = s.productExceptSelf(nums2);
    for (auto c : result2) {
        cout << c << ",";
    }
}