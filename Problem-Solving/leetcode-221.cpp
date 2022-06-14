// Maximal Square

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> newMatrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                newMatrix[i][j] = matrix[i][j] - '0';
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (newMatrix[i][j] != 0) {
                    newMatrix[i][j] =
                        min({newMatrix[i - 1][j - 1], newMatrix[i - 1][j],
                             newMatrix[i][j - 1]}) +
                        1;
                }
            }
        }
        int ans = 0;
        for (auto x : newMatrix) {
            for (auto c : x) {
                cout << c << ",";
                ans = max(ans, c);
            }
            cout << endl;
        }

        return ans * ans;
    }
};

int main() {
    Solution s;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << s.maximalSquare(matrix);
}