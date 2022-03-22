// Sort Array By Parity i.e. All Even Number must be before odd number

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for (auto x : nums) {
            if (x % 2 == 0) {
                result.push_back(x);
            }
        }
        for (auto x : nums) {
            if (x % 2 != 0) {
                result.push_back(x);
            }
        }

        return result;
    }

    vector<int> sortArrayByParity2(vector<int>& nums2) {
        int n = nums2.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (nums2[j] % 2 == 0) {
                swap(nums2[i], nums2[j]);
                i++;
            } else {
                j--;
            }
        }

        return nums2;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 2, 4, 7, 8};
    vector<int> result = s.sortArrayByParity(nums);
    for (auto x : result) {
        cout << x << ",";
    }

    cout << endl;
    vector<int> nums2 = {2, 1, 8};
    vector<int> result2 = s.sortArrayByParity(nums2);
    for (auto x : result2) {
        cout << x << ",";
    }
}