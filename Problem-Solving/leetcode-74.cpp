// Search in 2D Matrix

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int searchRow = -1;
        for (int i = 0; i < m; i++) {
            if (matrix[i][n - 1] >= target) {
                searchRow = i;
                break;
            }
        }

        if (searchRow == -1) return false;

        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = (s + e) / 2;

            if (matrix[searchRow][mid] == target) {
                // cout << searchRow << " and " << mid << endl;
                return true;
            } else if (matrix[searchRow][mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << s.searchMatrix(matrix, target);
}