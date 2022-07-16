#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canAllocateKstudent(vector<int> nums, int mid, int k) {
        int n = nums.size();
        int students = 1;
        int current_pages = 0;
        for (int i = 0; i < n; i++) {
            if (current_pages + nums[i] > mid) {
                current_pages = nums[i];
                students++;
                if (students > k) return false;
            } else {
                current_pages += nums[i];
            }
        }
        return true;
    }

    int allocateBookPages(vector<int> &nums, int k) {
        int n = nums.size();
        if (k > n) return -1;
        int s = 0;
        int e = 0;
        int total_pages = 0;

        for (auto x : nums) {
            total_pages += x;
            s = max(s, x);
        }

        e = total_pages;

        int ans = s;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (canAllocateKstudent(nums, mid, k)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 20, 30, 40};
    int k = 2;
    cout << s.allocateBookPages(nums, k);
}