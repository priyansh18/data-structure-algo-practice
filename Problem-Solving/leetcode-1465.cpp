// Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxArea(int h, int w, vector<int>& horizontalCuts,
                vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        int M = 1000000007;

        int maxH = INT_MIN;
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                maxH = max(maxH, horizontalCuts[i]);
            } else if (i == n) {
                maxH = max(maxH, h - horizontalCuts[i - 1]);
            } else {
                maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
            }
        }

        int maxV = INT_MIN;
        for (int i = 0; i <= m; i++) {
            if (i == 0) {
                maxV = max(maxV, verticalCuts[i]);
            } else if (i == m) {
                maxV = max(maxV, w - verticalCuts[i - 1]);
            } else {
                maxV = max(maxV, verticalCuts[i] - verticalCuts[i - 1]);
            }
        }

        return ((long long)(maxH)*maxV) % M;
    }
};

int main() {
    Solution s;
    int h = 5;
    int w = 4;
    vector<int> horizontalCuts = {1, 2, 4};
    vector<int> verticalCuts = {1, 3};
    cout << s.maxArea(h, w, horizontalCuts, verticalCuts);
}