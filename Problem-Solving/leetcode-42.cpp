// Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftBoundary(n);
        leftBoundary[0] = heights[0];
        for (int i = 1; i < n; i++) {
            leftBoundary[i] = max(heights[i], leftBoundary[i - 1]);
        }

        vector<int> rightBoundary(n);
        rightBoundary[n - 1] = heights[n - 1];

        for (int j = n - 2; j >= 0; j--) {
            rightBoundary[j] = max(heights[j], rightBoundary[j + 1]);
        }

        int maxWater = 0;
        for (int i = 0; i < n; i++) {
            int water = min(rightBoundary[i], leftBoundary[i]) - heights[i];
            if (water > 0) maxWater += water;
        }

        return maxWater;
    }
};

class Solution2 {
   public:
    //    This Approach is making sure that if my curr left is less than or
    //    equal which means that there is some building greater than curr left
    //    or viceversa.
    int trap(vector<int> heights) {
        int n = heights.size();
        int l = 0;
        int r = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (l <= r) {
            if (heights[l] <= heights[r]) {
                heights[l] > leftMax ? leftMax = heights[l]
                                     : water += leftMax - heights[l];
                l++;
            } else {
                heights[r] > rightMax ? rightMax = heights[r]
                                      : water += rightMax - heights[r];
                r--;
            }
        }

        return water;
    }
};

int main() {
    Solution s;
    Solution2 s2;
    vector<int> heights = {4, 2, 0, 2, 3, 5};
    cout << s.trap(heights) << endl;
    cout << s2.trap(heights) << endl;
}