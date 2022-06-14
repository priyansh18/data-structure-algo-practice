#include <bits/stdc++.h>
using namespace std;

// O(n^2 Approach)
class Solution2 {
   public:
    int findRightGreater(vector<int> &heights, int i, int n) {
        stack<int> st;
        st.push(heights[i]);
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (st.top() < heights[j]) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }

    int findLeftGreater(vector<int> &heights, int i, int n) {
        stack<int> st;
        st.push(heights[i]);
        int count = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (st.top() < heights[j]) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }

    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                result.push_back((findRightGreater(heights, i, n) + 1) *
                                 heights[i]);
            else if (i == n - 1)
                result.push_back((findLeftGreater(heights, i, n)) * heights[i]);
            else {
                result.push_back((findLeftGreater(heights, i, n) +
                                  findRightGreater(heights, i, n) + 1) *
                                 heights[i]);
            }
        }
        int ans = 0;
        for (auto x : result) {
            ans = max(ans, x);
        }
        return ans;
    }
};

// O(n) Approach
class Solution {
   public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() and heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty())
                left[i] = -1;
            else
                left[i] = s.top();
            s.push(i);
        }

        for (auto x : left) {
            cout << x << ",";
        }
        cout << endl;
        stack<int> s2;
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() and heights[s2.top()] >= heights[i]) {
                s2.pop();
            }
            if (s2.empty())
                right[i] = n;
            else
                right[i] = s2.top();
            s2.push(i);
        }

        for (auto x : right) {
            cout << x << ",";
        }
        cout << endl;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, (right[i] - left[i] - 1) * heights[i]);
        }

        return maxArea;
    }
};

int main() {
    Solution s;
    Solution2 s2;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    // cout << s2.largestRectangleArea(heights);
    cout << s.largestRectangleArea(heights);
}