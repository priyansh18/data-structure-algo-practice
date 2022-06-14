#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            int waterFilled = min(leftMax[i], rightMax[i]) - height[i];
            if (waterFilled > 0) totalWater += waterFilled;
        }

        return totalWater;
    }
};

int main() {
    Solution s;
    vector<int> height = {5,2,3,1,9,6,4,3};
    cout << s.trap(height) << endl;
}