// Wiggle Sort

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    //  O(nlogn) Algorithm.
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 1; i < n - 1; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }

    void wiggleSortOpt(vector<int> &nums) {
        int n = nums.size();
        for (int i = 1; i < n; i += 2) {
            if (i > 0 and nums[i] < nums[i - 1]) {
                swap(nums[i], nums[i - 1]);
            }
            if (i < n - 1 and nums[i] < nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 5, 2, 1, 6, 4};
    s.wiggleSort(nums);
    for (auto x : nums) {
        cout << x << ",";
    }
    cout << endl;
    vector<int> nums2 = {3, 5, 2, 1, 6, 4};
    s.wiggleSortOpt(nums2);
    for (auto x : nums2) {
        cout << x << ",";
    }
}