// Create Target Array in the Given Order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> target(n, -1);
        int val = 0;

        for (int i = 0; i < n; i++) {
            if (target[index[i]] == -1) {
                target[index[i]] = nums[i];
                val++;
            } else {
                for (int j = n - 1; j >= index[i]; j--) {
                    target[j] = target[j - 1];
                }
                target[index[i]] = nums[i];
            }
        }

        return target;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> index = {0, 1, 2, 1, 1, 0, 0, 2};

    vector<int> result = s.createTargetArray(nums, index);

    for (auto x : result) {
        cout << x << ",";
    }
}