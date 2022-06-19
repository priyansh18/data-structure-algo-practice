// Walls & Gates

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        // write your code here
        int m = rooms.size();
        int n = rooms[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int newDx = temp.second.first + dx[k];
                int newDy = temp.second.second + dy[k];

                if (newDx >= 0 and newDy >= 0 and newDx < m and newDy < n and
                    rooms[newDx][newDy] != -1 and !visited[newDx][newDy]) {
                    visited[newDx][newDy] = 1;
                    rooms[newDx][newDy] = temp.first + 1;
                    q.push({rooms[newDx][newDy], {newDx, newDy}});
                }
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{2147483647, -1, 0, 2147483647},
                                {2147483647, 2147483647, 2147483647, -1},
                                {2147483647, -1, 2147483647, -1},
                                {0, -1, 2147483647, 2147483647}};

    s.wallsAndGates(grid);
    for (auto x : grid) {
        for (auto c : x) {
            cout << c << ",";
        }
        cout << endl;
    }
}