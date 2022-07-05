// Find K Pairs with smallest sum

#include <bits/stdc++.h>
using namespace std;

class valPair {
   public:
    int sum;
    int x;
    int y;

    valPair(int sum, int x, int y) {
        this->sum = sum;
        this->x = x;
        this->y = y;
    }
};

class Compare {
   public:
    bool operator()(valPair A, valPair B) { return A.sum > B.sum; }
};

class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        priority_queue<valPair, vector<valPair>, Compare> p;
        vector<vector<int>> result;
        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        while (i < m) {
            p.push(valPair(nums1[i] + nums2[0], i, 0));
            i++;
        }

        while (!p.empty() and k--) {
            auto first = p.top();
            p.pop();

            result.push_back({nums1[first.x], nums2[first.y]});

            if (first.y + 1 < n) {
                p.push(valPair(nums1[first.x] + nums2[first.y + 1], first.x,
                               first.y + 1));
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 5;
    vector<vector<int>> result = s.kSmallestPairs(nums1, nums2, k);
    for (auto x : result) {
        for (auto y : x) {
            cout << y << ",";
        }
        cout << endl;
    }
}