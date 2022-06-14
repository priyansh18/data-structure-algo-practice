// Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
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

int main() {
    Solution s;
    vector<int> heights = {4, 2, 0, 2, 3, 5};
    cout << s.largestRectangleArea(heights) << endl;
}