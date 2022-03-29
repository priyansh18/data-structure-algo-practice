// Rotate the Array K times

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Constant Space O(1) but Time complexity is O(n*k)
    void rotateOnce(vector<int>& nums, int k) {
        int n = nums.size();
        int temp = nums[n - 1];

        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }

        nums[0] = temp;
    }

    void rotate1(vector<int>& nums, int k) {
        while (k--) {
            rotateOnce(nums, k);
        }
    }

    void reverseArr(vector<int>& nums2, int s, int e) {
        int i = s;
        int j = e;
        while (i < j) {
            swap(nums2[i], nums2[j]);
            i++;
            j--;
        }
    }

    void rotate2(vector<int>& nums2, int k) {
        int n = nums2.size();
        k = k % n;
        reverseArr(nums2, n - k, n - 1);
        reverseArr(nums2, 0, n - k - 1);
        reverseArr(nums2, 0, n - 1);
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    int n = nums.size();
    s.rotate1(nums, k);

    for (auto x : nums) {
        cout << x << ",";
    }

    cout << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7, 8};
    k = k%n;
    s.rotate2(nums2, k);

    for (auto x : nums2) {
        cout << x << ",";
    }

    return 0;
}
