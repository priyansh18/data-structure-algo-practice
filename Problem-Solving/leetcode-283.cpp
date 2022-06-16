// Move Zeroes

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        for(int i =0;i<n;i++){
          if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
          }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (auto x : nums) {
        cout << x << ",";
    }
}