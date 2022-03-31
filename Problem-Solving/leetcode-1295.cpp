// Find number with even number of digits.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isEven(int x) {
        int mod = 0;
        while (x) {
            mod++;
            x = x / 10;
        }

        if (mod % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }

    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (auto x : nums) {
            if (isEven(x)) {
                count++;
            }
        }

        return count;
    }

    int findNumbers2(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (auto x : nums) {
            int  val = floor(log10(x))+1;
            if (val%2==0) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {12, 345, 22, 6, 7896};
    cout << s.findNumbers(nums) << endl;
    cout << s.findNumbers2(nums) << endl;
}