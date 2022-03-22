// Count Number of Inversion in an numsay.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int mergeAndCount(vector<int> &nums, vector<int> &temp, int low, int mid,
                      int high) {
        int inv_count = 0;
        int i = low;
        int j = mid;
        int k = low;

        while ((i <= mid - 1) && (j <= high)) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
                inv_count = inv_count + (mid - i);
            }
        }

        while (i <= mid - 1) temp[k++] = nums[i++];

        while (j <= high) temp[k++] = nums[j++];

        return inv_count;
    }
    
    int countInversion(vector<int> &nums, vector<int> &temp, int low,
                       int high) {
        if (low >= high) {
            return 0;
        }

        int mid = (low + high) / 2;
        int left = countInversion(nums, temp, low, mid);
        int right = countInversion(nums, temp, mid + 1, high);
        int combine = mergeAndCount(nums, temp, low, mid + 1, high);
        return left + right + combine;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 5, 1, 7, 9};
    int n = nums.size();
    vector<int> temp(n);
    int low = 0;
    int high = n - 1;
    cout << s.countInversion(nums, temp, low, high) << endl;
    for (auto x : temp) {
        cout << x << ",";
    }
}