// Find All Lonely Numbers in the Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> m;
        for (auto x : nums) {
            m[x]++;
        }
        vector<int> result;
        for (auto x : nums) {
            if (m[x] == 1 and m.count(x - 1) == 0 and m.count(x + 1) == 0) {
                result.push_back(x);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 5, 6, 8};
    vector<int> result = s.findLonely(nums);
    for (auto x : result) {
        cout << x << ",";
    }
}