// Set Matrix Zeroes

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> arrI(m);
        vector<int> arrJ(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    arrI[i] = 1;
                    arrJ[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arrI[i] == 1 or arrJ[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }

        
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    s.setZeroes(nums);

    for (auto x : nums) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}