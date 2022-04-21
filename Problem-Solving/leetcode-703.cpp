// Kth Largest Element in a stream.

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            if (minHeap.size() < k)
                minHeap.push(nums[i]);
            else {
                if (nums[i] > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            } 
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
            return minHeap.top();
        } else {
            if (val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
                return minHeap.top();
            } else {
                return minHeap.top();
            }
        }
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest El = KthLargest(k, nums);
    cout << El.add(3) << endl;
    cout << El.add(5) << endl;
    cout << El.add(10) << endl;
    cout << El.add(9) << endl;
    cout << El.add(4) << endl;
}