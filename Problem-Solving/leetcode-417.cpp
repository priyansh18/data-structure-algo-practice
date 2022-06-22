// Pacific Atlantic water flow

#include <bits/stdc++.h>
using namespace std;

class ValPair {
   public:
    int val;
    int x;
    int y;

    ValPair(int val, int x, int y) {
        this->val = val;
        this->x = x;
        this->y = y;
    }
};

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) {
        int n11 = A.size();
        int n12 = A[0].size();

        queue<ValPair> q1;
        queue<ValPair> q2;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        vector<vector<int>> blue_lake(n11, vector<int>(n12, 0));
        vector<vector<int>> red_lake(n11, vector<int>(n12, 0));

        for (int i = 0; i < n11; i++) {
            for (int j = 0; j < n12; j++) {
                if (i == 0 or j == 0) {
                    q1.push(ValPair(A[i][j], i, j));
                }

                if (i == n11 - 1 or j == n12 - 1) {
                    q2.push(ValPair(A[i][j], i, j));
                }
            }
        }

        while (!q1.empty()) {
            auto temp = q1.front();
            blue_lake[temp.x][temp.y] = 1;
            q1.pop();

            for (int k = 0; k < 4; k++) {
                int newDx = temp.x + dx[k];
                int newDy = temp.y + dy[k];

                while (newDx >= 0 and newDy >= 0 and newDx < n11 and
                       newDy < n12 and !blue_lake[newDx][newDy] and
                       A[newDx][newDy] >= temp.val) {
                    blue_lake[newDx][newDy] = 1;
                    q1.push(ValPair(A[newDx][newDy], newDx, newDy));
                }
            }
        }

        while (!q2.empty()) {
            auto temp = q2.front();
            red_lake[temp.x][temp.y] = 1;
            q2.pop();

            for (int k = 0; k < 4; k++) {
                int newDx = temp.x + dx[k];
                int newDy = temp.y + dy[k];

                while (newDx >= 0 and newDy >= 0 and newDx < n11 and
                       newDy < n12 and !red_lake[newDx][newDy] and
                       A[newDx][newDy] >= temp.val) {
                    red_lake[newDx][newDy] = 1;
                    q2.push(ValPair(A[newDx][newDy], newDx, newDy));
                }
            }
        }

        vector<vector<int>> res;

        for (int i = 0; i < n11; i++) {
            for (int j = 0; j < n12; j++) {
                if (blue_lake[i][j] == red_lake[i][j]) {
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    res.push_back(ans);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4}};
    vector<vector<int>> result = s.pacificAtlantic(heights);
    for (auto x : result) {
        for (auto y : x) {
            cout << y << ",";
        }
        cout << endl;
    }
}