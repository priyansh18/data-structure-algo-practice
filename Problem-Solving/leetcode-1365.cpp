// How Many Numbers Are Smaller Than the Current Number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(100, 0);
        vector<int> pref(100, 0);

        for (auto x : nums) {
            freq[x]++;
        }

        for (int i = 1; i < 101; i++) {
            pref[i] = freq[i-1] + pref[i - 1];
        }

        vector<int> result;

        for (auto x : nums) {
            result.push_back(pref[x]);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {8, 1, 2, 2, 3};

    vector<int> r = s.smallerNumbersThanCurrent(nums);

    for (auto x : r) {
        cout << x << ",";
    }
    return 0;
}