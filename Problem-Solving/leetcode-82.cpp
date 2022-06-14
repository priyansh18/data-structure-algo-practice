
#include <bits/stdc++.h>
using namespace std;
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

        for (auto x : leftBoundary) {
            cout << x << ",";
        }
        cout << endl;
        for (auto x : rightBoundary) {
            cout << x << ",";
        }
        cout << endl;

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = rightBoundary[i] - leftBoundary[i] - 1;
            int area = width * heights[i];
            cout << area << endl;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    // cout << s2.largestRectangleArea(heights);
    cout << s.largestRectangleArea(heights);
}
