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
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(nums,1) << endl;
    cout << s.findKthSmallest(nums,2) << endl;
}