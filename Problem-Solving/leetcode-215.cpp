// Find Kth largest / Kth smallest Element Inside an array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (auto x : nums) {
            heap.push(x);
        }
        while (--k) {
            heap.pop();
        }

        return heap.top();
    }

    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto x : nums) {
            heap.push(x);
        }
        while (--k) {
            heap.pop();
        }

        return heap.top();
    }

    // Quick Select
    int partition(vector<int>& nums, int s, int e) {
        int pivot = nums[e];
        int i = s;
        for (int j = s; j <= e - 1; j++)
            if (nums[j] <= pivot) swap(nums[i++], nums[j]);
        swap(nums[i], nums[e]);
        return i;
    }

    int usingQuickSelect(vector<int>& nums, int k, int s, int e) {
        int n = nums.size();
        if (s > e) return -1;

        int idx = partition(nums, s, e);

        if (idx == n - k) return nums[idx];
        if (idx < n - k)
            return usingQuickSelect(nums, k, idx + 1, e);
        else
            return usingQuickSelect(nums, k, s, idx - 1);
    }

    int findKthLargestOpt(vector<int>& nums, int k) {
        return usingQuickSelect(nums, k, 0, nums.size() - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    // cout << s.findKthLargest(nums, 1) << endl;
    // cout << s.findKthSmallest(nums, 2) << endl;
    cout << s.findKthLargestOpt(nums, 2) << endl;
}