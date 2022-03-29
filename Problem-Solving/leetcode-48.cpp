//  Rotate Image -- Rotate Matrix by 90 deg

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Anti-Clockwise  -- Transpose then reverse.
    void rotate(vector<vector<int>>& matrix2) {
        int m = matrix2.size();
        int n = matrix2[0].size();

        // Transpose the matrix2.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    swap(matrix2[i][j], matrix2[j][i]);
                }
            }
        }

        // Reverse the matrix2.
        for (int j = 0; j < n; j++) {
            int s = 0;
            int e = n - 1;

            while (s <= e) {
                swap(matrix2[s][j], matrix2[e][j]);
                s++;
                e--;
            }
        }
    }

    // Clockwise  -- Reverse then transpose .

    void rotateClk(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Reverse the matrix.
        for (int j = 0; j < n; j++) {
            int s = 0;
            int e = n - 1;

            while (s <= e) {
                swap(matrix[s][j], matrix[e][j]);
                s++;
                e--;
            }
        }

        // Transpose the matrix.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Clockwise
    s.rotateClk(matrix);
    // Anticlockwise
    s.rotate(matrix2);

    for (auto x : matrix) {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
    cout<<endl;

    for (auto x : matrix2) {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
}