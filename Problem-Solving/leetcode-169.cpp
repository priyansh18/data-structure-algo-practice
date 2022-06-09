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
                    count=1;
                }
            }
            cout << majority << " and "<<count << endl;
        }

        return majority;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1, 1, 2, 3, 1, 4};
    cout << s.majorityElement(nums) << endl;
}