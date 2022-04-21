// Convert min heap to max heap.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void heapify(vector<int> &nums, int i) {
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        int minIdx = i;

        if (leftChild < nums.size() and nums[leftChild] < nums[i]) {
            minIdx = leftChild;
        }
        if (rightChild < nums.size() and nums[rightChild] < nums[i]) {
            minIdx = rightChild;
        }

        if (minIdx != i) {
            swap(nums[i], nums[minIdx]);
            heapify(nums, minIdx);
        }
    }
    void minToMaxHeap(vector<int> &nums) {
        int n = nums.size();
        for (int i = n; i < n; i++) {
            heapify(nums, i);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 12, 11, 20, 15};
    s.minToMaxHeap(nums);
    for (auto x : nums) {
        cout << x << ",";
    }
}