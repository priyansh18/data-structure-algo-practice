// Majority Element II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int candidate1 = 0;
        int candidate2 = 0;
        int life1 = 0;
        int life2 = 0;
        for (auto x : nums) {
            if (x == candidate1) {
                life1++;
            } else if (x == candidate2) {
                life2++;
            } else if (life1 == 0) {
                candidate1 = x;
                life1++;
            } else if (life2 == 0) {
                candidate2 = x;
                life2++;
            } else {
                life1--;
                life2--;
            }
        }

        int count1 = 0;
        int count2 = 0;
        for (auto x : nums) {
            if (candidate1 == x) count1++;
            if (candidate2 == x) count2++;
        }

        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 2, 3, 5, 6};
    vector<int> result = s.majorityElement(nums);
    for (auto x : result) {
        cout << x << ",";
    }
}