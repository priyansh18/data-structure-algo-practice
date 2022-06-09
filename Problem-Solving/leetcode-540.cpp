// Single Element in a sorted array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s < e) {
            int mid = (s + e) / 2;
            if (mid - 1 >= 0 and mid + 1 < n and nums[mid - 1] != nums[mid] and
                nums[mid + 1] != nums[mid])
                return nums[mid];
            if (mid + 1 < n and nums[mid] == nums[mid + 1] and
                (mid - s) % 2 == 0)
                s = mid + 2;
            if (mid + 1 < n and nums[mid] == nums[mid + 1] and
                (mid - s) % 2 == 1)
                e = mid - 1;
            if (mid - 1 >= 0 and nums[mid] == nums[mid - 1] and
                (mid - s) % 2 == 1)
                s = mid + 1;
            if (mid - 1 >= 0 and nums[mid] == nums[mid - 1] and
                (mid - s) % 2 == 0)
                e = mid - 2;
        }

        if (s == e) return nums[s];

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << s.singleNonDuplicate(nums) << endl;
}