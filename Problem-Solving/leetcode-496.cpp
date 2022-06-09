// Next Greater Element I

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> s;
        vector<int> result;
        for (int j = n2 - 1; j >= 0; j--) {
            if (s.empty()) {
                result.push_back(-1);
            } else {
                if (nums2[j] > s.top()) {
                    while (!s.empty() and nums2[j] > s.top()) {
                        s.pop();
                    }
                    if (s.empty()) result.push_back(-1);
                    if (!s.empty() and nums2[j] < s.top()) result.push_back(s.top());
                } else {
                    result.push_back(s.top());
                }
            }
            s.push(nums2[j]);
        }

        reverse(result.begin(), result.end());

        unordered_map<int, int> m;

        for (int i = 0; i < n2; i++) {
            m[nums2[i]] = result[i];
        }

        for (auto x : m) {
            cout << x.first << " and " << x.second << endl;
        }

        vector<int> ans(n1);
        for (int i = 0; i < n1; i++) {
            ans[i] = m[nums1[i]];
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = s.nextGreaterElement(nums1, nums2);
    for (auto x : result) {
        cout << x << ",";
    }
    return -1;
}