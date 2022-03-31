// The K weakest rows in a matrix.

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        set<pair<int, int>> s;

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            s.insert({count,i});
        }

        for (auto x : s) {
            if(k>0){
              result.push_back(x.second);
              k--;
            }
        }

        
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 1, 0, 0, 0},
                                  {1, 1, 1, 1, 0},
                                  {1, 0, 0, 0, 0},
                                  {1, 1, 0, 0, 0},
                                  {1, 1, 1, 1, 1}};

    vector<int> result = s.kWeakestRows(matrix, 3);

    for (auto x : result) {
        cout << x << ",";
    }
}