// Contains Duplicates III

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j <= min(n-1, i+k); ++j){
                if(abs((long long)nums[i]-nums[j]) <= t){
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 9, 1, 5, 9};
    int t = 3;
    int k = 2;
    cout << s.containsNearbyAlmostDuplicate(nums, k, t) << endl;
}