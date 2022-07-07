// Majority Element

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = nums[0];
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == majority) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    majority = nums[i];
                    count = 1;
                }
            }
        }

        return majority;
    }
};

class Solution2 {
   public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int life = 0;
        for (auto x : nums) {
            if (x == candidate) {
                life++;
            } else {
                if (life == 0) {
                    candidate = x;
                    life++;
                } else {
                    life--;
                }
            }
        }

        return candidate;
    }
};

int main() {
    Solution s;
    Solution2 s2;
    vector<int> nums = {1, 2, 1, 1, 2, 3, 1, 4};
    cout << s.majorityElement(nums) << endl;
    cout << s2.majorityElement(nums) << endl;
}