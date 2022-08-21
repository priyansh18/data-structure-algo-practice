// Remove duplicates from sorted array

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i + 1;
        while (j < n) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                nums[i + 1] = nums[j];
                i++;
                j++;
            }
        }
        i++;
        while (i < n) {
            nums.pop_back();
            i++;
        }
        return nums.size();
    }
};