//  Count Negative numbers in a sorted array

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // O(m*n) Approach
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] < 0) {
                    count++;
                }
            }
        }

        return count;
    }
    // O(m+n) Approach
    int countNegativeOpt(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int i = m - 1;
        int j = 0;
        while (i >= 0 and j < n) {
            /* code */
            if (grid[i][j] < 0) {
                count += n - j;
                i--;
            } else {
                j++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};

    cout << s.countNegatives(matrix) << endl;

    vector<vector<int>> matrix2 = {
        {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};

    cout << s.countNegativeOpt(matrix2) << endl;
}