// Largest Rectangle in histogram.

#include <bits/stdc++.h>
using namespace std;

// O(n) solution -- using stack
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftBoundary(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 and heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                leftBoundary[i] = -1;
            } else {
                leftBoundary[i] = st.top();
            }
            st.push(i);
        }

        vector<int> rightBoundary(n, 0);
        stack<int> st1;
        for (int i = n - 1; i >= 0; i--) {
            while (st1.size() > 0 and heights[st1.top()] >= heights[i]) {
                st1.pop();
            }
            if (st1.size() == 0) {
                rightBoundary[i] = n;
            } else {
                rightBoundary[i] = st1.top();
            }
            st1.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = rightBoundary[i] - leftBoundary[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// Brute Force Solution -- TLE
class Solution2 {
   public:
    int findLeftIndex(vector<int> heights, int index) {
        int j = index - 1;
        while (j >= 0 and heights[j] >= heights[index]) {
            j -= 1;
        }
        return j;
    }

    int findRightIndex(vector<int> heights, int index) {
        int j = index + 1;
        while (j < heights.size() and heights[j] >= heights[index]) {
            j += 1;
        }
        return j;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = -1;

        for (int i = 0; i < n; i++) {
            int leftIndex = findLeftIndex(heights, i);
            int rightIndex = findRightIndex(heights, i);
            int currentArea = (rightIndex - leftIndex - 1) * heights[i];
            cout << currentArea << " and " << leftIndex << " and " << rightIndex
                 << endl;

            maxArea = max(maxArea, currentArea);
        }

        return maxArea;
    }
};

int main() {
    Solution2 s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(heights) << endl;

    Solution ss;
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << ss.largestRectangleArea(heights1) << endl;
}