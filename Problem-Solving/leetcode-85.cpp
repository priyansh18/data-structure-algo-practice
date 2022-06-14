// Maximum Rectangle in Binary Matrix.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
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

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, (right[i] - left[i] - 1) * heights[i]);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> newMatrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                newMatrix[i][j] = matrix[i][j] - '0';
            }
        }

        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(newMatrix[0][j]);
        }
        int maxArea = largestRectangleArea(v);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (newMatrix[i][j] == 0) {
                    v[j] = 0;
                } else {
                    v[j] = v[j] + newMatrix[i][j];
                }
            }
            maxArea = max(maxArea, largestRectangleArea(v));
        }

        return maxArea;
    }
};

int main() {
    Solution s;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << s.maximalRectangle(matrix);
}