// Find the single number whose frequency is one and all other's have frequency 2 without using exra space

//  Best Solution : XOR. 

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0;
        for (auto x : nums) {
            x1 ^= x;
        }

        return x1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << s.singleNumber(nums);
}