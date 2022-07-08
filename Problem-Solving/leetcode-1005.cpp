// Maximize sum of array after k Negations
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 and k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int x = *min_element(nums.begin(),nums.end());

        if(k&1) sum -= 2*x;

        return sum; 
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, -3, -1, 5, 4};
    int k = 2;
    cout << s.largestSumAfterKNegations(nums, k) << endl;
}