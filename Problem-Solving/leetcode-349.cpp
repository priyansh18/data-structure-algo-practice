// Intersection of two array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> result;
        set<int> s;
        while (i < n1 and j < n2) {
            if (nums1[i] == nums2[j]) {
                s.insert(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        for (auto x : s) {
            result.push_back(x);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {0, 4, 9, 8, 4};
    vector<int> result = s.intersection(nums1, nums2);
    for (auto x : result) {
        cout << x << ",";
    }
}