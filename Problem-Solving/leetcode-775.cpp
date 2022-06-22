// Global and local inversion

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int localInversions(vector<int>& nums) {
        // Local Inversion are those who index is in range 0 to n-1 and
        // a[index]>a[index+1]
        int n = nums.size();
        int inv = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) inv++;
        }

        return inv;
    }

    int mergeInversions(vector<int>& nums, int s, int e) {
        vector<int> temp;
        int mid = (s + e) / 2;
        int i = s;
        int j = mid + 1;
        int inv = 0;

        while (i <= mid and j <= e) {
            if (nums[i] < nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                inv += mid - i + 1;
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        while (j <= e) {
            temp.push_back(nums[j++]);
        }

        for (int i = s; i <= e; i++) {
            nums[i] = temp[i - s];
        }

        return inv;
    }

    int globalInversions(vector<int>& nums, int s, int e) {
        int inv = 0;
        if (s < e) {
            int mid = (s + e) / 2;
            inv += globalInversions(nums, s, mid);
            inv += globalInversions(nums, mid + 1, e);
            inv += mergeInversions(nums, s, e);
        }

        return inv;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int localInv = localInversions(nums);
        int globalInv = globalInversions(nums, 0, n - 1);
        return localInv == globalInv;
    }
};

class Solution {
   public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxV = -1;
        for (int i = 0; i < n - 2; i++) {
            maxV = max(maxV, nums[i]);
            if (maxV > nums[i + 2]) return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {6, 2, 5, 4, 3, 1};
    cout << s.isIdealPermutation(nums) << endl;
    for (auto x : nums) cout << x << ",";
}