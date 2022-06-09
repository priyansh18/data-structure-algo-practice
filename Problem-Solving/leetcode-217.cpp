// Contains Duplicates

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m(0);

        for (auto x : nums) {
            m[x]++;
        }

        for (auto x : m) {
            cout << x.first << " and " << x.second << endl;
        }

        for (auto x : m) {
            if (m[x.first] > 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.containsDuplicate(nums) << endl;
}