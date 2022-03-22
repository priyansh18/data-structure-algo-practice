// Find two missing number in a sequence of consecutive numbers.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void printTwoMissingNumber(vector<int> nums) {
        int n = nums.size();
        int xorr = 0;
        for (int i = 1; i <= n + 2; i++) {
            xorr ^= i;
        }
        for (auto x : nums) {
            xorr ^= x;
        }

        // getting first set bit
        int tmp = xorr;
        int pos = 0;
        while (true) {
            if (tmp & 1) break;
            pos++;
            tmp >>= 1;
        }
        // Create a mask to check number have same bit place.
        int mask = 1 << pos;

        int set1Xor = 0;
        int set2Xor = 0;

        for (auto x : nums) {
            if ((x & mask) == 0) {
                set1Xor ^= x;
            } else {
                set2Xor ^= x;
            }
        }
        for (int i = 1; i <= n + 2; i++) {
            if ((i & mask) == 0) {
                set1Xor ^= i;
            } else {
                set2Xor ^= i;
            }
        }

        cout << set1Xor << " " << set2Xor << endl;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    s.printTwoMissingNumber(nums);
}