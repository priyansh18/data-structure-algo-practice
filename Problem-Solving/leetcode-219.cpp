// Contain Duplicates II

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m(0);

        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i]) != 0) {
                if (abs(m[nums[i]] - i) <= k)
                    return true;
                else
                    m[nums[i]] = i;
            } else {
                m[nums[i]] = i;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << s.containsNearbyDuplicate(nums, k) << endl;
}